

workspace "GEEK"
	
	starup = "GE"
	graphicsEngine = "GE"
	IncludeDir = {}

	IncludeDir["glfw"] = "%{wks.location}/GE/External/glfw/include"
	IncludeDir["glad"] = "%{wks.location}/GE/External/glad/include"
	
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
	group ""

	group "BuildScript"
		project "Script"
		kind "Utility"
			files {
				"./**.lua",
				"./GE/premake5.lua",
				"./GE/External/glfw/premake5.lua",
				"./GE/External/glad/premake5.lua"
			}
