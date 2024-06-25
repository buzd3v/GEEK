#pragma once

#include "Core/Delegate.h"
#include "Core/IModule.h"
#include "GLFW/glfw3.h"

namespace Geek {
	class InputModule : public IModule
	{
		friend class ActionMgr;

	private:
		Delegate<GLFWwindow*, int, int, int, int> m_keyCallbaks;
		Delegate<GLFWwindow*, int, int, int> m_mouseCallbaks;

	public:
		InputModule() = default;
		~InputModule() = default;

		// Inherited via IModule
		void Startup() override;
		void Update(float deltaTime) override;
		void Shutdown() override;

		// static function to handling input callback

		static u64

	};
};