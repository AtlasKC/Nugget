workspace "Nugget"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Nugget"
	location "Nugget"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "nepch.h"
	pchsource "Nugget/src/nepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"NE_PLATFORM_WINDOWS",
			"NE_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "NE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "NE_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Nugget/vendor/spdlog/include",
		"Nugget/src"
	}

	links
	{
		"Nugget"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"NE_PLATFORM_WINDOWS",
		}
		
	filter "configurations:Debug"
		defines "NE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "NE_DIST"
		optimize "On"