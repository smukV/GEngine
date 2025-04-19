workspace "GEngine"
    architecture "x64"

    startproject "Sandbox"
    
    configurations
    {
        "Debug",
        "Profile",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GEngine"
    location "GEngine"
    kind "StaticLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/source/**.h",
        "%{prj.name}/source/**.hpp",
        "%{prj.name}/source/**.c",
        "%{prj.name}/source/**.cpp",
        "%{prj.name}/source/**.cppm"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "on"
        systemversion "latest"

    filter "configurations: Debug"
        defines "Debug"
        symbols "on"

    filter "configurations: Profile"
        defines "Profile"
        symbols "on"
        optimize "on"

    filter "configurations: Release"
        defines "Release"
        optimize "on"

project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"
    
        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
        files
        {
            "%{prj.name}/source/**.h",
            "%{prj.name}/source/**.hpp",
            "%{prj.name}/source/**.c",
            "%{prj.name}/source/**.cpp",
            "%{prj.name}/source/**.cppm"
        }
    
        links
        {
            "GEngine"
        }
    
        filter "system:windows"
            cppdialect "C++20"
            staticruntime "on"
            systemversion "latest"
    
        filter "configurations: Debug"
            defines "Debug"
            symbols "on"
    
        filter "configurations: Profile"
            defines "Profile"
            symbols "on"
            optimize "on"
    
        filter "configurations: Release"
            defines "Release"
            optimize "on"
