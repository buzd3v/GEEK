#include "Action.h"


Geek::Action::Action()
{
	m_configName = "";
	m_KeyCode = KeyCode::NONE;
	m_mouseButton = MouseButton::NONE;
	m_state = ButtonState::NONE;
}

void Geek::Action::BindToConfig(pugi::xml_node& root)
{
	SET_CONFIG_VAR_STR(keyCode);
}

void Geek::Action::_ParseToKeyCode(std::string keyCode)
{
}
