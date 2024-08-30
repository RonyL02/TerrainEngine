cmake_minimum_required(VERSION 3.15)

project(Sandbox)

# Source files for the Sandbox executable
file(GLOB_RECURSE SANDBOX_SRC src/*.cpp)

# Add the Sandbox executable
add_executable(Sandbox ${SANDBOX_SRC})

# Link the Engine library to the Sandbox executable
target_link_libraries(Sandbox PUBLIC Engine)

# Specify include directories for the Sandbox executable
target_include_directories(Sandbox PUBLIC ../engine/src)

# Set the properties for compiler options
target_compile_features(Sandbox PUBLIC cxx_std_${CMAKE_CXX_STANDARD})
