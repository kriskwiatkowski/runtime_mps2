cmake_minimum_required(VERSION 3.10)
include(FetchContent)

project(stm32l4_runtime LANGUAGES C ASM)
set(MAIN_TARGET mps2-an386_runtime)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_C_STANDARD 99)
set(OUTPUT ${CMAKE_BINARY_DIR}/pack)
set(CMAKE_INSTALL_BINDIR ${OUTPUT}/bin)
set(CMAKE_INSTALL_LIBDIR ${OUTPUT}/lib)
set(CMAKE_INSTALL_SRCDIR ${OUTPUT}/src)
set(CMAKE_INSTALL_INCLUDEDIR ${OUTPUT}/include/platform)
set(LINKER_SCRIPT_SRC ${PROJECT_SOURCE_DIR}/src/mps2.src.ld)
set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/mps2.ld)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}")

include(postbuild)

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    string(APPEND CMAKE_C_FLAGS " -O0")
endif()


add_library(
    ${MAIN_TARGET} STATIC
    src/handlers.c
    src/init.c
    src/printf.c
    src/startup.S)

target_sources(
    ${MAIN_TARGET}
    PUBLIC
    FILE_SET HEADERS
    FILES
        ${CMAKE_SOURCE_DIR}/inc/platform/printf.h
        ${CMAKE_SOURCE_DIR}/inc/platform/platform.h
    BASE_DIRS
        ${CMAKE_SOURCE_DIR}/inc/platform)

target_compile_definitions(
    ${MAIN_TARGET} PRIVATE
    ${EXTRA_C_FLAGS}
    -DDATA_IN_FLASH)

target_include_directories(
    ${MAIN_TARGET}
    PUBLIC
        ${CMAKE_SOURCE_DIR}/inc)


# Generate linker script
add_custom_command(
    OUTPUT ${LINKER_SCRIPT} PRE_BUILD
    DEPENDS ${LINKER_SCRIPT_SRC}
    COMMAND ${CMAKE_C_COMPILER} -x assembler-with-cpp -DDATA_IN_FLASH -E -Wp,-P -I${CMAKE_SOURCE_DIR}/src ${LINKER_SCRIPT_SRC} -o ${LINKER_SCRIPT}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating linker script for MPS2-ANS386"
    VERBATIM)
add_custom_target(
    ${MAIN_TARGET}_link
    DEPENDS ${LINKER_SCRIPT})
add_dependencies(
    ${MAIN_TARGET} ${MAIN_TARGET}_link)

add_executable(
    hello
    app/hello.c
    src/handlers.c)

target_link_libraries(
    hello
    ${MAIN_TARGET})

target_link_options(
    hello PRIVATE
    "-T${LINKER_SCRIPT}" -nostartfiles)
target_postbuild_executable(hello ${CMAKE_INSTALL_BINDIR})

install(
    TARGETS ${MAIN_TARGET}
    ARCHIVE
    PUBLIC_HEADER
    FILE_SET HEADERS)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/hello.bin
    DESTINATION ${CMAKE_INSTALL_BINDIR})

install(
    FILES
        ${LINKER_SCRIPT}
    DESTINATION
        ${CMAKE_INSTALL_LIBDIR})

install(
    FILES
        ${CMAKE_SOURCE_DIR}/src/handlers.c
    DESTINATION
        ${CMAKE_INSTALL_SRCDIR})
