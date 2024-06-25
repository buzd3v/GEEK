#pragma once

#include "Core/Delegate.h"
#include "Core/IModule.h"
#include "GLFW/glfw3.h"
#include "KeyCode.h"
#include "glm/glm.hpp"
#include "ActionMgr.h"


namespace Geek {
	class InputModule : public IModule
	{
		friend class ActionMgr;

	private:
		using KeyCallbackMap = std::unordered_map<std::pair<int, Modifier>, Delegate<>, KeyPairHash<int,Modifier>, KeyPairEqual<int,Modifier>>;
		using MouseCallbackMap = std::unordered_map<int, Delegate<>>;

		static KeyCallbackMap m_keyPressCallbacks;
		static KeyCallbackMap m_keyReleaseCallbacks;

		static MouseCallbackMap m_mousePressCallbacks;
		static MouseCallbackMap m_mouseReleaseCallbacks;

	public:
		InputModule() = default;
		~InputModule() = default;

		// Inherited via IModule
		void Startup() override;
		void Startup(GLFWwindow* window);
		void Update(float deltaTime) override;
		void Shutdown() override;

		// static function to handling input callback

		//direct handling
		 bool IsKeyPress(KeyCode key);
		 glm::vec2 GetMousePosition();
		 bool IsMousePress(MouseButton button);

		//register callback to key
		static u64 RegisterKeyPressCallback(KeyCode keyCode, Modifier mod,u64 key, const Callback<>& callback);
		static u64 RegisterKeyReleaseCallback(KeyCode keyCode, Modifier mod,u64 key, const Callback<>& callback);

		//register callback to mouse button
		static u64 RegisterMousePressCallback(MouseButton btn, const Callback<>& callback);
		static u64 RegisterMouseReleaseCallback(MouseButton btn, const Callback<>& callback);


	private:
		//Input listener: bind this listener to glfw callback function
		static void KeyboardListener(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void MouseButtonListener(GLFWwindow* window, int button, int action, int mods);
	};
};