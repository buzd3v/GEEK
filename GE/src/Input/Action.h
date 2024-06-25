#pragma once
#include "Core/Alias.h"
#include "Core/IConfigVar.h"
#include "KeyCode.h"

namespace Geek
{
	class Action : public IConfigVar
	{

	private:

		KeyCode m_keyCode;
		MouseButton m_mouseButton; //TODO: added support for gamepad later
		Modifier m_modifier;
		KeyState m_state;

	public:
		Action();
		~Action() {}
		// Inherited via IConfigVar
		void BindToConfig(pugi::xml_node& root) override;

		Modifier& GetModifier() { return m_modifier; }
		KeyCode& GetKeycode() { return m_keyCode; }
		MouseButton& GetMouseButton() { return m_mouseButton; }
		KeyState& GetState() { return m_state; }
	};

} // namespace Geek