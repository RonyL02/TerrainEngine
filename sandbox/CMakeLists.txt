project(TerrainEngine-sandbox)

file(GLOB_RECURSE SANDBOX_SOURCES src/*.cpp)

add_executable(${exe_name} ${SANDBOX_SOURCES})

target_link_libraries(${exe_name} PUBLIC ${lib_name})