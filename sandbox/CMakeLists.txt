project(TerrainEngine-sandbox)

add_executable(${exe_name} src/main.cpp)

target_link_libraries(${exe_name} PRIVATE TerrainEngine)

set_target_properties(${exe_name} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)