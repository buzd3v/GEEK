#pragma once
#include "Core/IConfigVar.h"
#include "Singleton.h"
#include <string>

namespace Geek {
	
	class WindowConfig : public SingletonDclp<WindowConfig> , public IConfigVar
	{
	public:
		WindowConfig(std::string filePath);
		void BindToConfig() override;

	private: 
		int m_screenWidth;
		int m_screenHeight;
		std::string m_windowName;
		bool b_showCusor;
		bool b_fullScreen;
	};

};