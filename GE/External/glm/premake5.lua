project "glm"
	kind "StaticLib"
	language "C++"

	targetdir ("build/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"*.hpp",
	}
	includedirs
    {
        "./"
    }