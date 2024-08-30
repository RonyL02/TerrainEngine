cmake_minimum_required(VERSION 3.15)

# Set the project name and C++ standard
project(YourProject CXX)

# Set the default build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Option to switch between static and dynamic linking
option(BUILD_SHARED_LIBS "Build shared libraries instead of static" OFF)

# Option to choose the C++ standard version
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optionally specify the architecture (default to native)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
set(CMAKE_PREFIX_PATH "./vcpkg_installed/x64-windows/share/glfw3")

message("${CMAKE_PREFIX_PATH}")


# Include the Engine and Sandbox subdirectories
add_subdirectory(Engine)
add_subdirectory(Sandbox)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(DIRECTORY PROPERTY VS_STARTUP_PROJECT "Sandbox")
