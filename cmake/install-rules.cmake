# ---- Install runtime lib ----
set(EXPORT_TARGET ${RUNNER_TARGET}_target)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${package}ConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

install(
    TARGETS ${RUNNER_TARGET}
    EXPORT ${EXPORT_TARGET}
    ARCHIVE
    PUBLIC_HEADER
    FILE_SET HEADERS)

install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/${package}ConfigVersion.cmake DESTINATION ${CMAKE_INSTALL_PREFIX})
install(
    FILES ${LINKER_SCRIPT} DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR})

install(
    EXPORT ${EXPORT_TARGET}
    NAMESPACE ${RUNNER_TARGET}::
    DESTINATION "${CMAKE_INSTALL_PREFIX}")

# ---- Install sample app ----
install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/hello.bin
    DESTINATION ${CMAKE_INSTALL_BINDIR})

include(CPack)
