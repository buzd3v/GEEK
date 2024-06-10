#pragma once
#include "../IWindowAPI.h"

namespace Geek {
	namespace WindowAPI {
		class GlfwWindow : public IWindowAPI
		{
		private:

			GLFWwindow* m_windowHandle;

		public:
			void CreateContext() override;
			void InitProperty(WindowType type, int width, int height) override;
			void CreateWindow() override;
			void Shutdown() override;
		};
	};
};


