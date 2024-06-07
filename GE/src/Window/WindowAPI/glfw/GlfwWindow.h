#pragma once
#include "../IWindowAPI.h"

namespace Geek {
	namespace WindowAPI {
		class GlfwWindow : public IWindowAPI
		{
			void CreateContext() override;
			void CreateWindow() override;
		};
	};
};


