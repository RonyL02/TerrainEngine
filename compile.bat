rm -rf build/*
cmake --preset default -G "Unix Makefiles"  . -B ./build 
cmake --build build