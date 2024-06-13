#pragma once
#include "Core/IConfigVar.h"
#include "Singleton.h"
#include <string>
#include "WindowAPI/glfw/GlfwWindow.h"
namespace Geek {
	
	class WindowConfig : public IConfigVar
	{
		friend class WindowModule;
		friend class WindowAPI::GlfwWindow;

	public:
		WindowConfig() = default;
		~WindowConfig() = default;

		//Because Config just have primitive attrb so we dont need to implement all this constructor and assignment
		//copy constructor & copy assignment
		WindowConfig(const WindowConfig& other) = default;
		WindowConfig& operator=(const WindowConfig& other) = default;

		//move constructor & move assignment
		WindowConfig(WindowConfig&& other) = default;
		WindowConfig& operator=(WindowConfig&& other) = default;

		void BindToConfig(pugi::xml_node& root) override;

	protected: 
		int m_screenWidth;
		int m_screenHeight;
		std::string m_windowName;
		bool b_showCusor;
		bool b_fullScreen;
	};

};