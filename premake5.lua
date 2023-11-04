workspace "incoil"
architecture "x64"

configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "incoil"
	location "."
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++14"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files { "src/**.h", "src/**.cpp" }

	filter "system:windows"
	systemversion "latest"
			
	filter "configurations:Debug"
	defines { "DEBUG" }
	runtime "Debug"
	symbols "On"

	filter "configurations:Release"
	defines { "NDEBUG" }
	runtime "Release"
	optimize "On"
