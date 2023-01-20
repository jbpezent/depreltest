
set(CMAKE_VERBOSE_MAKEFILE TRUE)

add_custom_target(pypiwheel  ALL DEPENDS ${CMAKE_SOURCE_DIR}/depreltest)
add_dependencies(pypiwheel _depreltest)

set(WHEEL_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/depreltest)

set(ASSET_BINARY_NAME "_depreltest${PYTHON_MODULE_EXTENSION}")


configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/setup.py.in"
    "${CMAKE_CURRENT_BINARY_DIR}/setup.py"
    @ONLY)


add_custom_command(TARGET pypiwheel 
                    COMMAND ${CMAKE_COMMAND} -E rm -rf ${WHEEL_BUILD_DIR}/
                    COMMENT "Cleaning depreltest install directory")


add_custom_command(TARGET pypiwheel 
                    COMMAND ${CMAKE_COMMAND} -E copy_directory  ${CMAKE_SOURCE_DIR}/depreltest
                                                ${WHEEL_BUILD_DIR}/depreltest
                    DEPENDS ${CMAKE_SOURCE_DIR}/depreltest
                    COMMENT "Copied depreltest to ${WHEEL_BUILD_DIR}")

add_custom_command(TARGET pypiwheel 
                    COMMAND ${CMAKE_COMMAND} -E copy  ${CMAKE_CURRENT_BINARY_DIR}/setup.py ${WHEEL_BUILD_DIR}
                    
                    COMMENT "Copied setup.py to ${WHEEL_BUILD_DIR}")


add_custom_command(TARGET pypiwheel 
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:_depreltest> ${WHEEL_BUILD_DIR}/
    COMMENT "Copied asset.pyd to ${WHEEL_BUILD_DIR}"
    )




add_custom_command(TARGET pypiwheel 
                    COMMAND
                   ${PYTHON_EXECUTABLE} ${WHEEL_BUILD_DIR}/setup.py bdist_wheel 
                   WORKING_DIRECTORY ${WHEEL_BUILD_DIR}
                   COMMENT "Generating Binary Wheel")


message(STATUS ${ASSET_BINARY_NAME})
#add_custom_command(TARGET pypiwheel POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:asset> ${PYTHON_LOCAL_INSTALL_DIR}/
#    COMMENT "Copied asset.pyd to ${PYTHON_LOCAL_INSTALL_DIR}"
#    )


