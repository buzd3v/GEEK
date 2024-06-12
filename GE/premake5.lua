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
		"imgui",
		"assimp",
		"pugixml"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE",
		"STB_IMAGE_IMPLEMENTATION",
		"PUGIXML_HEADER_ONLY"
	}

	includedirs
	{
		"src",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.imgui}",
		"%{IncludeDir.pugixml}",
		"%{IncludeDir.sid}",
	}
	
	files
	{
		"src/**.h",
		"src/**.cpp",
		"src/Material/**.cpp",
		"src/Material/**.h",
		"src/Graphic/**.h",
		"src/Graphic/**.cpp",
		"src/Core/**.cpp",
		"src/Core/**.h",
		"src/API/**.cpp",
		"src/API/**.h",
		"src/Window/**.cpp",
		"src/Window/**.h",
		"src/Window/WindowAPI/**.cpp",
		"src/Window/WindowAPI/**.h",
		"src/Window/WindowAPI/GlfwWindow/**.cpp",
		"src/Window/WindowAPI/GlfwWindow/**.h",


	}
	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"