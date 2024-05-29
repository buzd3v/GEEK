project "GE"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	links {
		"glfw",
		"glad",
		--"stb_image",
		"opengl32.lib",
		"imgui"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE",
		"STB_IMAGE_IMPLEMENTATION",
	}

	includedirs
	{
		"src",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.imgui}"
	}
	
	files
	{
		"src/**.h",
		"src/**.cpp",
		"src/Material/**.cpp",
		"src/Material/**.h",
	}
	