#pragma once
#include "../IWindowAPI.h"
#include <string>
#include <GLFW/glfw3.h>

namespace Geek {
	namespace WindowAPI {
		class GlfwWindow : public IWindowAPI
		{
		private:

			GLFWwindow* m_windowHandle;

		public:
			void CreateContext() override;
			void CreateWindow() override;
			void Shutdown() override;
		};
	};
};


