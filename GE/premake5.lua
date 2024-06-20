project "GE"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	libdirs { 
	 	"./External/vld/lib/Win64"
	}

	links {
		"glfw",
		"glad",
		"opengl32.lib",
		"imgui",
		"assimp",
		"pugixml",
		"vld"
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
		"%{IncludeDir.vld}",
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
	
function copyVldNeeded()
    return {
        "{COPY} External/vld/bin/Win64/** %{cfg.targetdir}/bin/Debug/",
    }
end	
	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"
		postbuildcommands (copyVldNeeded())
            

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

