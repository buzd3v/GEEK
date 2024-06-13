#include "WindowConfig.h"

using namespace Geek;

void Geek::WindowConfig::BindToConfig(pugi::xml_node& root)
{
    SET_CONFIG_VAR(configName, string); //MUST IMPLEMENT THIS LINE OF CODE FOR ALL CONFIG
		SET_CONFIG_VAR(screenWidth, int);
    SET_CONFIG_VAR(screenHeight, int);
    SET_CONFIG_VAR(windowName, string);
    SET_CONFIG_B_VAR(showCusor, bool);
    SET_CONFIG_B_VAR(fullScreen, bool);
}
