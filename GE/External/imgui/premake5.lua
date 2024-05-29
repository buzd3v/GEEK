project "imgui"
	kind "StaticLib"
	language "C++"

	targetdir ("build/" .. outputdir .. "/%{prj.name}")

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"
		links
		{
			"glfw"
		}

		files
		{
			"*.cpp",
			"backends/imgui_impl_glfw.cpp",
			"backends/imgui_impl_opengl3.cpp",
			"misc/cpp/imgui_stdlib.cpp"
		}

		includedirs
		{
			"./",
			"../glfw/include"
		}

		defines 
		{ 
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
