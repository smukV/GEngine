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
IncludeDirs = {}
IncludeDirs["GLFW"] = "GEngine/3rd-party/GLFW/include"


project "GEngine"
    location "GEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/source/**.h",
        "%{prj.name}/source/**.hpp",
        "%{prj.name}/source/**.c",
        "%{prj.name}/source/**.cpp",
        "%{prj.name}/source/**.cppm"
    }

    includedirs
    {
        "%{prj.name}/3rd-party/spdlog/include",
        "%{IncludeDirs.GLFW}"
    }

    libdirs
    {
        "%{prj.name}/3rd-party/GLFW/"
    }

    links
    {
        "glfw3"
    }

    buildoptions {"/utf-8"}
    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        defines {"Debug"}
        symbols "on"

    filter "configurations:Profile"
        defines {"Profile"}
        symbols "on"
        optimize "on"

    filter "configurations:Release"
        defines {"Release"}
        optimize "on"

project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++20"
    
        targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
        objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")
    
        files
        {
            "%{prj.name}/source/**.h",
            "%{prj.name}/source/**.hpp",
            "%{prj.name}/source/**.c",
            "%{prj.name}/source/**.cpp",
            "%{prj.name}/source/**.cppm"
        }
    
        includedirs
        {
            "GEngine/source",
            "GEngine/3rd-party/spdlog/include"
        }

        links
        {
            "GEngine"
        }

        buildoptions {"/utf-8"}

        filter "system:windows"
            systemversion "latest"
    
        filter "configurations:Debug"
            defines {"Debug"}
            symbols "on"
    
        filter "configurations:Profile"
            defines {"Profile"}
            symbols "on"
            optimize "on"
    
        filter "configurations:Release"
            defines {"Release"}
            optimize "on"
