-- premake5.lua (Root)
workspace "TerrainEngine"
    location "build"
    configurations { "Debug", "Release" }
    platforms { "x64" }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    if _ACTION == "clean" then
        os.rmdir("build")
    end

    startproject "Sandbox"

    filter "platforms:x64"
        architecture "x64"
    
    filter "system:windows"
        defines { "PLATFORM_WINDOWS" }
        systemversion "latest"
    
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
    
    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
    
    include "Engine"
    include "Sandbox"
