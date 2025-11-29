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
)