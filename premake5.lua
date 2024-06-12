

workspace "GEEK"
	
	starup = "GE"
	graphicsEngine = "GE"
	IncludeDir = {}

	IncludeDir["glfw"] = "%{wks.location}/GE/External/glfw/include"
	IncludeDir["glad"] = "%{wks.location}/GE/External/glad/include"
	IncludeDir["stb_image"] = "%{wks.location}/GE/External/stb_image"
	IncludeDir["glm"] = "%{wks.location}/GE/External/glm"
	IncludeDir["imgui"] = "%{wks.location}/GE/External/imgui"
	IncludeDir["pugixml"] = "%{wks.location}/GE/External/pugixml/src"
	IncludeDir["sid"] = "%{wks.location}/GE/External/string-id"


	architecture "x86_64"
	startproject ("GE")

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	include "Sandbox"
	include "GE"

	group "Dependencies" 
		include "./GE/External/glfw"
		include "./GE/External/glad"
		include "./GE/External/stb_image"
		include "./GE/External/glm"
		include "./GE/External/imgui"
		include "./GE/External/assimp"
		include "./GE/External/pugixml"

	group ""

	group "BuildScript"
		project "Script"
		kind "Utility"
			files {
				"./**.lua",
				"./GE/premake5.lua",
				"./GE/External/glfw/premake5.lua",
				"./GE/External/glad/premake5.lua",
				"./GE/External/stb_image/premake5.lua",
				"./GE/External/glm/premake5.lua",
				"./GE/External/imgui/premake5.lua",
				"./GE/External/assimp/premake5.lua",
				"./GE/External/pugixml/premake5.lua",


			}
	group "ShaderFile"
		project "ShaderFile"
		kind "Utility"
			files{
				"./GE/ShaderFile/**.vert",
				"./GE/ShaderFile/**.frag",
			}