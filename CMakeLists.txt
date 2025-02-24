cmake_minimum_required(VERSION 3.10)

project(
    mps2_runtime
    VERSION 0.0.2
    LANGUAGES C ASM)

enable_language(C)
enable_language(ASM)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_C_STANDARD 99)

set(RUNNER_TARGET mps2_runtime)
set(CMAKE_INSTALL_SRCDIR src)
set(CMAKE_INSTALL_LIBDIR lib) # Force LIBDIR to "lib" name.
set(CMAKE_INSTALL_INCLUDEDIR include/platform)
set(LINKER_SCRIPT_SRC ${PROJECT_SOURCE_DIR}/src/mps2.src.ld)
set(LINKER_SCRIPT ${PROJECT_SOURCE_DIR}/mps2.ld)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}")

include(GNUInstallDirs)
include(cmake/postbuild)

# ---- Declare target library ----

add_library(
    ${RUNNER_TARGET} STATIC
    src/handlers.c
    src/init.c
    src/printf.c
    src/startup.S)

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
    ${EXTRA_C_FLAGS}
    -DDATA_IN_FLASH)

target_compile_options(
    ${RUNNER_TARGET} PUBLIC
    -march=${CMAKE_SYSTEM_PROCESSOR} -mfloat-abi=soft -mthumb)

target_include_directories(
    ${RUNNER_TARGET} PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:inc>)

# Generate linker script
add_custom_command(
    OUTPUT ${LINKER_SCRIPT} PRE_BUILD
    DEPENDS ${LINKER_SCRIPT_SRC}
    COMMAND ${CMAKE_C_COMPILER} -x assembler-with-cpp -DDATA_IN_FLASH -E -Wp,-P -I${PROJECT_SOURCE_DIR}/src ${LINKER_SCRIPT_SRC} -o ${LINKER_SCRIPT}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMENT "Generating linker script for MPS2-ANS386"
    VERBATIM)

add_custom_target(
    ${RUNNER_TARGET}_genlink
    DEPENDS ${LINKER_SCRIPT})

add_dependencies(
    ${RUNNER_TARGET} ${RUNNER_TARGET}_genlink)

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
    "-T${LINKER_SCRIPT}" -nostartfiles
    -Wl,--whole-archive $<TARGET_FILE_NAME:${RUNNER_TARGET}> -Wl,--no-whole-archive)

target_postbuild_executable(hello ${CMAKE_INSTALL_BINDIR})

include(cmake/install-rules.cmake)

set(CPACK_GENERATOR "TGZ")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_FILE_NAME "${RUNNER_TARGET}_${FLAVOUR}_${PROJECT_VERSION}")
include(CPack)
