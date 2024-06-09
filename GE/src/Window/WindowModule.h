#pragma once
#include "Core/IModule.h"
#include <string>

namespace Geek {

	enum class WindowType;
	class WindowAPI::IWindowAPI;
	class Window;

	struct WindowConfig {
		int width, height;
		WindowType type;

		WindowConfig(int width, int height, WindowType type) : width(width), height(height), type(type) {}
	};

	class WindowModule : public IModule {
	public:

		void Startup() override;
		void Update(float deltaTime) override;
		void Shutdown() override;

	private:
		WindowConfig m_config;
		IWindowAPI m_windowAPI;

	private:
		std::string m_apiType;
	};

}; //namespace Geek