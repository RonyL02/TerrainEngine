include(FetchContent)

set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)
set(SDL_TESTS OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-3.4.12
)

FetchContent_MakeAvailable(SDL3)

add_library(TerrainEngine STATIC)

file(GLOB_RECURSE TERRAIN_ENGINE_MODULES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cppm"
)

file(GLOB_RECURSE TERRAIN_ENGINE_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

target_sources(TerrainEngine
    PUBLIC
        FILE_SET cxx_modules TYPE CXX_MODULES
        BASE_DIRS
            src
        FILES
            ${TERRAIN_ENGINE_MODULES}

    PRIVATE
        ${TERRAIN_ENGINE_SOURCES}
)

target_link_libraries(TerrainEngine
    PRIVATE
        SDL3::SDL3-static
)
