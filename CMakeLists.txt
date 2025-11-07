cmake_minimum_required(VERSION 3.16)

project(TerrainEngine)

include("${CMAKE_CURRENT_LIST_DIR}/cmake/CPM.cmake")

add_subdirectory(engine)
add_subdirectory(sandbox)