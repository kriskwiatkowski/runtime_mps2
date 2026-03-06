# ---- Install runtime lib ----
set(EXPORT_TARGET ${RUNNER_TARGET}_target)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${RUNNER_TARGET}ConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/${RUNNER_TARGET}ConfigVersion.cmake
    DESTINATION ".")
install(
    FILES ${LINKER_SCRIPT}
    DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(
    TARGETS ${RUNNER_TARGET}
    EXPORT ${EXPORT_TARGET}
    ARCHIVE
    PUBLIC_HEADER
    FILE_SET HEADERS)
install(
    EXPORT ${EXPORT_TARGET}
    NAMESPACE ${RUNNER_TARGET}::
    DESTINATION "cmake")

# ---- Install sample app ----
# Install the ELF as hello.bin: QEMU identifies ELF by magic bytes (not extension),
# so this lets `qemu-system-arm ... -kernel out/an521/hello.bin` load correctly.
install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/hello
    DESTINATION .
    RENAME hello.bin)
