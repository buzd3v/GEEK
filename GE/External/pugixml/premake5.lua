project "pugixml"
	kind "StaticLib"
	language "C++"

	targetdir ("build/" .. outputdir .. "/%{prj.name}")

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"

		files
		{
			"src/pugixml.cpp", 
			"src/pugixml.hpp",
			"src/pugiconfig.hpp",
		}

		defines 
		{ 
			"_GLFW_WIN32",
			"_CRT_SECURE_NO_WARNINGS",
			"PUGIXML_HEADER_ONLY"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
