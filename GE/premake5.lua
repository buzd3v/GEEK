project "GE"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	links {
		"glfw",
		"glad",
		"opengl32.lib"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE",
	}

	includedirs
	{
		"src",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.glad}",
	}
	
	files
	{
		"src/**.h",
		"src/**.cpp",
	}
	