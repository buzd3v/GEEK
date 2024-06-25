#pragma once
#include "../IWindowAPI.h"
#include <GLFW/glfw3.h>
#include <string>

namespace Geek {
	namespace WindowAPI {
		class GlfwWindow : public IWindowAPI
		{
		private:


		public:
			GLFWwindow* m_windowHandle;
			void CreateContext() override;
			void CreateWindow() override;
			void Update(float deltaTime) override;
			void Shutdown() override;
		};
	};
};


