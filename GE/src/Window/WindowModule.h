#pragma once
#include "Core/IModule.h"
#include <string>
#include "WindowAPI/glfw/GlfwWindow.h"

namespace Geek {
	class WindowModule : public IModule {

	public:
		WindowModule() = default;

		void Startup() override;
		void Update(float deltaTime) override;
		void Shutdown() override;


		WindowAPI::GlfwWindow* m_window;
	private:
	};

}; //namespace Geek