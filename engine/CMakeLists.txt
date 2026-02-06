project(TerrainEngine-lib)

# Fetch raylib
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)
FetchContent_MakeAvailable(raylib)

file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
        src/*.cpp
)

add_library(${lib_name} STATIC ${ENGINE_SOURCES})

target_include_directories(${lib_name}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${lib_name} PUBLIC raylib)