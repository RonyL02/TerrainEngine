cmake_minimum_required(VERSION 3.16)

project(TerrainEngine)

include("${CMAKE_CURRENT_LIST_DIR}/cmake/CPM.cmake")

CPMAddPackage("gh:glfw/glfw#3.4")
option(glew-cmake_BUILD_SHARED NO)
CPMAddPackage(
    libglew_static
    GIT_REPOSITORY https://github.com/Perlmint/glew-cmake.git
    GIT_TAG        glew-cmake-2.2.0)
CPMAddPackage("gh:gabime/spdlog@1.16.0")
CPMAddPackage("gh:g-truc/glm#1.0.1")

CPMAddPackage(
  NAME stb
  GIT_REPOSITORY https://github.com/nothings/stb.git
  GIT_TAG master
  DOWNLOAD_ONLY YES
)


file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(${exe_name} ${SOURCES})

target_link_libraries(${exe_name} PRIVATE glfw)
target_link_libraries(${exe_name} PRIVATE opengl32)
target_link_libraries(${exe_name} PRIVATE libglew_static)
target_link_libraries(${exe_name} PRIVATE spdlog)
target_link_libraries(${exe_name} PRIVATE glm::glm)
if (stb_ADDED)
  target_include_directories(${exe_name} PRIVATE ${stb_SOURCE_DIR})
  target_sources(${exe_name} PRIVATE
  ${stb_SOURCE_DIR}/stb_image.h
)
endif()

set_target_properties(${exe_name} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin
)