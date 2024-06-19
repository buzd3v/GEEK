#pragma once
#include "Core/IConfigVar.h"
#include "KeyCode.h"
namespace Geek
{
	class Action : public IConfigVar
	{

	private:
		
		KeyCode m_KeyCode;
		MouseButton m_mouseButton; //TODO: added support for gamepad later
		ButtonState m_state;

	public:
		Action();
		~Action(){}
		// Inherited via IConfigVar
		void BindToConfig(pugi::xml_node& root) override;

	private:
		void _ParseToKeyCode(std::string keyCode);
	};
} // namespace Geek