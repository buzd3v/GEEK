#pragma once
#include "../IWindowAPI.h"
#include <GLFW/glfw3.h>
#include <string>

namespace Geek {
	namespace WindowAPI {
		class GlfwWindow : public IWindowAPI
		{
		private:

			GLFWwindow* m_windowHandle;

		public:
			void CreateContext() override;
			void CreateWindow() override;
			void Update(float deltaTime) override;
			void Shutdown() override;
		};
	};
};


