#include "WindowConfig.h"



void Geek::WindowConfig::BindToConfig()
{
		SET_CONFIG_VAR(screenWidth, int);
    SET_CONFIG_VAR(screenHeight, int);
    SET_CONFIG_VAR(windowName, string);
    SET_CONFIG_B_VAR(showCusor, bool);
    SET_CONFIG_B_VAR(fullScreen, bool);
}
