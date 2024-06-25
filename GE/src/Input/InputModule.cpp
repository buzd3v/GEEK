#include "InputModule.h"
using namespace Geek;

InputModule::KeyCallbackMap InputModule::m_keyPressCallbacks{};
InputModule::KeyCallbackMap InputModule::m_keyReleaseCallbacks{};
InputModule::MouseCallbackMap InputModule::m_mousePressCallbacks{};
InputModule::MouseCallbackMap InputModule::m_mouseReleaseCallbacks{};

void Geek::InputModule::Startup()
{

}

void Geek::InputModule::Startup(GLFWwindow* window)
{
	glfwSetKeyCallback(window, KeyboardListener);
	ActionMgr::Construct("Config/InputConfig.xml", "Config");
}

void Geek::InputModule::Update(float deltaTime)
{
	glfwPollEvents();
}

void Geek::InputModule::Shutdown()
{
}

bool Geek::InputModule::IsKeyPress(KeyCode key)
{
	return false;
}

glm::vec2 Geek::InputModule::GetMousePosition()
{
	return glm::vec2();
}

bool Geek::InputModule::IsMousePress(MouseButton button)
{
	return false;
}

u64 Geek::InputModule::RegisterKeyPressCallback(KeyCode keyCode, Modifier mod, u64 key, const Callback<>& callback)
{
	auto& callbackList = m_keyPressCallbacks[std::make_pair(static_cast<int>(keyCode), mod)];
	u64 result = callbackList.Subscribe(key, callback);

	return result;
}

u64 Geek::InputModule::RegisterKeyReleaseCallback(KeyCode keyCode, Modifier mod, u64 key, const Callback<>& callback)
{
	auto& callbackList = m_keyReleaseCallbacks[std::make_pair(static_cast<int>(keyCode), mod)];
	u64 result = callbackList.Subscribe(key, callback);
	return result;
}

u64 Geek::InputModule::RegisterMousePressCallback(MouseButton btn, const Callback<>& callback)
{
	return u64();
}

u64 Geek::InputModule::RegisterMouseReleaseCallback(MouseButton btn, const Callback<>& callback)
{
	return u64();
}

void Geek::InputModule::KeyboardListener(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		m_keyPressCallbacks[{key, static_cast<Modifier>(mods)}].Invoke();
	}
	else if (action == GLFW_RELEASE) {
		m_keyReleaseCallbacks[{key, static_cast<Modifier>(mods)}].Invoke();
	}
}

void Geek::InputModule::MouseButtonListener(GLFWwindow* window, int button, int action, int mods)
{
}
