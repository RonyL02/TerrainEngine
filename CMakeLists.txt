cmake_minimum_required(VERSION 4.2.0)

project(TerrainEngine)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(EXISTS "${CMAKE_BINARY_DIR}/compile_commands.json")
    file(COPY "${CMAKE_BINARY_DIR}/compile_commands.json"
         DESTINATION "${CMAKE_SOURCE_DIR}/build")
endif()

add_subdirectory(engine)
add_subdirectory(sandbox)