project(TerrainEngine-sandbox)

file(GLOB_RECURSE SANDBOX_SOURCES src/*.cpp)

add_executable(${exe_name} ${SANDBOX_SOURCES})

target_include_directories(${exe_name} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/../engine/include
)

target_link_libraries(${exe_name} PUBLIC ${lib_name})

set_target_properties(${exe_name} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/sandbox
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

add_custom_command(TARGET ${exe_name} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/res
    ${CMAKE_BINARY_DIR}/sandbox/res
    COMMENT "Copying resources to build directory"
)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_options(${exe_name} PRIVATE
        -g
        -O0
        -gcodeview
        -gdwarf
    )
endif()

