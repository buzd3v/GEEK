#include "Action.h"


Geek::Action::Action()
{
	m_configName = "";
	m_keyCode = KeyCode::NONE;
	m_mouseButton = MouseButton::NONE;
	m_modifier = Modifier::NONE;
	m_state = KeyState::PRESS;
}

#define GETVALUE(x) KeyCode::##x

void Geek::Action::BindToConfig(pugi::xml_node& root)
{
	SET_CONFIG_VAR(configName, string); //MUST IMPLEMENT THIS LINE OF CODE FOR ALL CONFIG

	//Set keycode enum
	SET_CONFIG_VAR_STR(keyCode);
	m_keyCode = GET_ENUM(KeyCode, keyCode);

	//Set mouse button
	SET_CONFIG_VAR_STR(mouseButton);
	m_mouseButton = GET_ENUM(MouseButton, mouseButton);

}

