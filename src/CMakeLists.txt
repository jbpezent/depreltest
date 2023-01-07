include_directories(${CMAKE_CURRENT_SOURCE_DIR})


set(ASSET_INCLUDES
  ${CMAKE_CURRENT_SOURCE_DIR}
  PARENT_SCOPE
)

#-------------------------------------------------------------------------------
## PCH
add_library(pch STATIC pch.h pch.cpp  )
target_precompile_headers(pch PRIVATE pch.h) 

target_include_directories(pch PRIVATE ${INCLUDE_DIRS})
#target_link_libraries(pch PRIVATE fmt::fmt-header-only)
target_compile_options(pch PUBLIC ${COMPILE_FLAGS})
#-------------------------------------------------------------------------------
## ASSET Python Module
pybind11_add_module(_depreltest main.cpp )


target_compile_options(_depreltest PUBLIC  ${COMPILE_FLAGS})
target_precompile_headers(_depreltest REUSE_FROM pch)
target_include_directories(_depreltest PRIVATE ${INCLUDE_DIRS})
target_link_libraries(_depreltest PRIVATE ${LINK_LIBS})

if(UNIX)
    set_target_properties(_depreltest PROPERTIES LINK_FLAGS ${LINKER_FLAGS})
endif()



add_custom_target(pysrc ALL DEPENDS ${CMAKE_SOURCE_DIR}/depreltest)


message(STATUS "CMAKE DIR LOC" ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "CMAKE PROJ LOC" ${INCLUDE_DIRS})

if(PYTHON_LOCAL_INSTALL_DIR)
    add_custom_command(TARGET _depreltest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:_depreltest> ${PYTHON_LOCAL_INSTALL_DIR}/
    COMMENT "Copied _depreltest.pyd to ${PYTHON_LOCAL_INSTALL_DIR}"
    )
    message(STATUS "Cleaning depreltest install directory")

    add_custom_command(TARGET pysrc POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E rm -rf ${PYTHON_LOCAL_INSTALL_DIR}/depreltest
                    COMMENT "Cleaning depreltest install directory")

    add_custom_command(TARGET pysrc POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_directory  ${CMAKE_SOURCE_DIR}/depreltest
                                                ${PYTHON_LOCAL_INSTALL_DIR}/depreltest
                    DEPENDS ${CMAKE_SOURCE_DIR}/depreltest
                    COMMENT "Copied depreltest to ${PYTHON_LOCAL_INSTALL_DIR}")

endif()


    




    


