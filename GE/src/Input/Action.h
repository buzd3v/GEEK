#pragma once
#include "Core/IConfigVar.h"
#include "KeyCode.h"
#include <any>
namespace Geek
{
	class IAction : public IConfigVar
	{

	private:
		
		KeyCode m_keyCode;
		MouseButton m_mouseButton; //TODO: added support for gamepad later

	public:
		IAction();
		~IAction(){}
		// Inherited via IConfigVar
		void BindToConfig(pugi::xml_node& root) override;

	private:
		void _ParseToKeyCode(std::string keyCode);

	};

	template<typename T, typename... args>
	class Action : IAction
	{
	protected:
		Callback<T, args...> callback;

	};
} // namespace Geek