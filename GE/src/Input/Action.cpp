#include "Action.h"


Geek::IAction::IAction()
{
	m_configName = "";
	m_keyCode = KeyCode::NONE;
	m_mouseButton = MouseButton::NONE;
}

#define GETVALUE(x) KeyCode::##x

void Geek::IAction::BindToConfig(pugi::xml_node& root)
{
	SET_CONFIG_VAR(configName, string); //MUST IMPLEMENT THIS LINE OF CODE FOR ALL CONFIG

	//Set keycode enum
	SET_CONFIG_VAR_STR(keyCode);
	m_keyCode = GET_ENUM(KeyCode, SID(keyCode));

	//Set mouse button
	SET_CONFIG_VAR_STR(mouseButton);
	m_mouseButton = GET_ENUM(MouseButton, SID(mouseButton));

}

void Geek::IAction::_ParseToKeyCode(std::string keyCode)
{
}
