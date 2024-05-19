project "stb_image"
	kind "StaticLib"
	language "C++"

	targetdir ("build/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"stb_image.h"
	}
	includedirs
    {
        "./"
    }
	
		
