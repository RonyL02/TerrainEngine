-- Sandbox/premake5.lua
project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    targetdir ("..bin/" .. outputdir)
    objdir ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

    files { "src/**.h", "src/**.cpp" }
    includedirs { "src", "../engine/src" }

    links { "Engine" }

    filter "system:windows"
        systemversion "latest"
        defines { "SANDBOX_PLATFORM_WINDOWS" }
    
    filter "configurations:Debug"
        defines { "SANDBOX_DEBUG" }
        runtime "Debug"
        symbols "On"
    
    filter "configurations:Release"
        defines { "SANDBOX_RELEASE" }
        runtime "Release"
        optimize "On"
