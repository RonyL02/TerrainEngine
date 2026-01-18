project(TerrainEngine-lib)

file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
        src/*.cpp
)

add_library(${lib_name} STATIC ${ENGINE_SOURCES})

target_include_directories(${lib_name}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)