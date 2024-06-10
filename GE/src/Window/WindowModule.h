#pragma once
#include "Core/IModule.h"
#include <string>
#include "WindowAPI/glfw/GlfwWindow.h"

namespace Geek {
	class WindowConfig;
	class WindowModule : public IModule {

	public:
		void Startup() override;
		void Update(float deltaTime) override;
		void Shutdown() override;

	private:
		WindowAPI::GlfwWindow* m_window;
	};


}; //namespace Geek