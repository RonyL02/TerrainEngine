project(TerrainEngine-lib)

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

file(GLOB_RECURSE ENGINE_SOURCES src/*.cpp)

add_library(${lib_name} STATIC ${ENGINE_SOURCES})

target_link_libraries(${lib_name} PUBLIC
    glfw
    opengl32
    libglew_static
    spdlog
    glm::glm
)

if (stb_ADDED)
  target_include_directories(${lib_name} PUBLIC ${stb_SOURCE_DIR})
  target_sources(${lib_name} PUBLIC ${stb_SOURCE_DIR}/stb_image.h)
endif()

target_include_directories(${lib_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)