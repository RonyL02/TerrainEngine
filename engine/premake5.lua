-- Engine/premake5.lua
project "Engine"
    kind "SharedLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    targetdir ("..bin/" .. outputdir)
    objdir ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

    files { "src/**.h", "src/**.cpp" }
    includedirs { "src/**.h", "../dependencies/includes/glfw" }

    -- Link GLFW
    libdirs { "../dependencies/libs/glfw" }
    links {"glfw3", "opengl32","gdi32" }

    filter "system:windows"
        systemversion "latest"
        defines { "ENGINE_PLATFORM_WINDOWS" }
    

    filter "configurations:Debug"
        defines { "ENGINE_DEBUG" }
        runtime "Debug"
        symbols "On"
    
    filter "configurations:Release"
        defines { "ENGINE_RELEASE" }
        runtime "Release"
        optimize "On"
