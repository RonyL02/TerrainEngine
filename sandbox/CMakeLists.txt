add_executable(sandbox)

file(GLOB_RECURSE SANDBOX_MODULES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cppm"
)

file(GLOB_RECURSE SANDBOX_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

target_sources(sandbox
    PRIVATE
        ${SANDBOX_SOURCES}

    PUBLIC
        FILE_SET cxx_modules TYPE CXX_MODULES
        BASE_DIRS
            src
        FILES
            ${SANDBOX_MODULES}
)

target_link_libraries(sandbox
    PRIVATE
        TerrainEngine
)
