#include "ActionMgr.h"
#include "InputModule.h"


inline void Geek::ActionMgr::Connect(std::string actionName, Callback<> callback)
{
	Action action = FindConfig(actionName);
	std::string name = action.GetName();
	
	//check if action not found
	if (name.empty()) {
		return;
	}

	//if found
	Modifier mod = action.GetModifier();
	KeyCode keycode = action.GetKeycode();
	MouseButton btn = action.GetMouseButton();
	KeyState state = action.GetState();

	switch(state)
	{
	case KeyState::PRESS:
		InputModule::RegisterKeyPressCallback(keycode, mod, SID_VAL(name.c_str()), callback);
		break;
	case KeyState::RELEASE:
		InputModule::RegisterKeyReleaseCallback(keycode, mod, SID_VAL(name.c_str()), callback);
		break;
	}
}

void Geek::ActionMgr::Disconnect(std::string actionName)
{
}

void Geek::ActionMgr::Invoke()
{
}

