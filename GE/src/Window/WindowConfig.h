#pragma once
#include "Core/IConfigVar.h"
#include "Singleton.h"
#include <string>
#include "WindowAPI/glfw/GlfwWindow.h"
namespace Geek {
	
	class WindowConfig : public SingletonDclp<WindowConfig> , public IConfigVar
	{
		friend class WindowModule;
		friend class WindowAPI::GlfwWindow;

	public:
		WindowConfig(std::string filePath);
		void BindToConfig() override;

	protected: 
		int m_screenWidth;
		int m_screenHeight;
		std::string m_windowName;
		bool b_showCusor;
		bool b_fullScreen;
	};

};