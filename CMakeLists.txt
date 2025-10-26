cmake_minimum_required(VERSION 3.10)

project(
    mps2_runtime
    VERSION 0.0.7
    LANGUAGES C ASM)

enable_language(C)
enable_language(ASM)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_C_STANDARD 99)

if(CMAKE_C_COMPILER_ID MATCHES "ARMCC")
  # True if ARMCC version is 5.x is used, otherwise FALSE.
  set(HAS_COMPILER_ARMCC_5 (defined(__ARMCC_VERSION) && (__ARMCC_VERSION < 6000000)))
endif()

set(RUNNER_TARGET mps2rtm)
set(CMAKE_INSTALL_SRCDIR src)
set(CMAKE_INSTALL_LIBDIR lib) # Force LIBDIR to "lib" name.
set(CMAKE_INSTALL_INCLUDEDIR include/platform)
if(HAS_COMPILER_ARMCC_5)
  set(LINKER_SCRIPT ${PROJECT_SOURCE_DIR}/src/startup_armcc/cortex-m3/MPS2.sct)
  include(config/comp_armcc_flags.cmake)
else()
  set(LINKER_SCRIPT_SRC ${PROJECT_SOURCE_DIR}/src/startup_gcc/mps2.src.ld)
  set(LINKER_SCRIPT ${PROJECT_SOURCE_DIR}/mps2.ld)
  include(config/comp_gcc_clang_flags.cmake)
endif()
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}")

include(GNUInstallDirs)
include(cmake/postbuild)

# ---- Declare target library ----

add_library(
    ${RUNNER_TARGET} STATIC
    src/handlers.c
    src/init.c
    src/printf.c)

if (HAS_COMPILER_ARMCC_5)
    target_sources(
        ${RUNNER_TARGET} PRIVATE
        src/startup_armcc/cortex-m3/startup.S)
    target_compile_options(${RUNNER_TARGET} PRIVATE --cpu=Cortex-M3)
else()
    target_sources(
        ${RUNNER_TARGET} PRIVATE
        src/startup_armcc/startup.S)
endif()

target_sources(
    ${RUNNER_TARGET}
    PUBLIC
    FILE_SET HEADERS
    FILES
        ${PROJECT_SOURCE_DIR}/inc/platform/printf.h
        ${PROJECT_SOURCE_DIR}/inc/platform/platform.h
    BASE_DIRS
        ${PROJECT_SOURCE_DIR}/inc/platform)

target_compile_definitions(
    ${RUNNER_TARGET} PUBLIC
    ${EXTRA_C_DEFINES}
    -DDATA_IN_FLASH
    -DMPS2_${FLAVOUR})

# Public interface compile options
target_compile_options(
    ${RUNNER_TARGET} PUBLIC
    ${EXTRA_C_COMPILE_OPTIONS})

target_include_directories(
    ${RUNNER_TARGET} PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:include>)

# Generate linker script. This is needed by arm-none-eabi-gcc toolchain.
if (NOT HAS_COMPILER_ARMCC_5)
    add_custom_command(
        OUTPUT ${LINKER_SCRIPT} PRE_BUILD
        DEPENDS ${LINKER_SCRIPT_SRC}
        COMMAND ${CMAKE_C_COMPILER} -x assembler-with-cpp -DDATA_IN_FLASH -E -Wp,-P -I${PROJECT_SOURCE_DIR}/src ${LINKER_SCRIPT_SRC} -o ${LINKER_SCRIPT}
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        COMMENT "Generating linker script for MPS2"
        VERBATIM)
    add_custom_target(
        ${RUNNER_TARGET}_genlink
        DEPENDS ${LINKER_SCRIPT})
    add_dependencies(
        ${RUNNER_TARGET} ${RUNNER_TARGET}_genlink)
endif()

include(GenerateExportHeader)
generate_export_header(
    ${RUNNER_TARGET}
    BASE_NAME ${RUNNER_TARGET}
    EXPORT_FILE_NAME export/${RUNNER_TARGET}/${RUNNER_TARGET}_export.h
)

# ---- Declare target sample app ----

add_executable(
    hello
    app/hello.c)

target_link_libraries(
    hello
    ${RUNNER_TARGET})

target_link_options(
    hello PRIVATE
    "-T${LINKER_SCRIPT}")
    #-nostartfiles
    #-Wl,--whole-archive $<TARGET_FILE_NAME:${RUNNER_TARGET}> -Wl,--no-whole-archive)

#target_postbuild_executable(hello ${CMAKE_INSTALL_BINDIR})

include(cmake/install-rules.cmake)

string(TOLOWER "${CMAKE_BUILD_TYPE}" CMAKE_BUILD_TYPE_LOW)

set(CPACK_GENERATOR "TGZ")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_FILE_NAME "${RUNNER_TARGET}_${FLAVOUR}_${PROJECT_VERSION}_${CMAKE_BUILD_TYPE_LOW}${PACK_CUSTOMIZATION}")
include(CPack)
