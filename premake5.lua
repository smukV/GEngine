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

VULKAN_SDK_PATH = os.getenv("VULKAN_SDK")

IncludeDirs = {}
IncludeDirs["spdlog"] = "GEngine/3rd-party/spdlog"
IncludeDirs["GLFW"] = "GEngine/3rd-party/GLFW"
IncludeDirs["Vulkan"] = "%{VULKAN_SDK_PATH}"


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
        "%{IncludeDirs.spdlog}/include",
        "%{IncludeDirs.GLFW}/include",
        "%{IncludeDirs.Vulkan}/include"
    }

    libdirs
    {
        "%{IncludeDirs.GLFW}/",
        "%{IncludeDirs.Vulkan}/lib/"
    }

    links
    {
        "glfw3",
        "vulkan-1"
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
            "%{IncludeDirs.spdlog}/include"
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
