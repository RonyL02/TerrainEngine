cmake_minimum_required(VERSION 3.15)

project(Engine)

# Source files for the Engine library
file(GLOB_RECURSE ENGINE_SRC src/*.cpp)

# Add the Engine library
add_library(Engine ${ENGINE_SRC})

# Specify the include directories for the Engine library
target_include_directories(Engine PUBLIC src)

# Link external libraries (e.g., GLFW)
set(glfw3_DIR "$ENV{VCPKG_ROOT}/installed/x64-windows-static/share/glfw3")
find_package(glfw3 CONFIG REQUIRED)  # Assuming you have GLFW3 installed
target_link_libraries(Engine PUBLIC glfw opengl32)

# Set the properties for static/dynamic linking and compiler options
target_compile_features(Engine PRIVATE cxx_std_${CMAKE_CXX_STANDARD})
set_target_properties(Engine PROPERTIES POSITION_INDEPENDENT_CODE ON)
