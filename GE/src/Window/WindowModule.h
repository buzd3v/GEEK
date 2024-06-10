#pragma once
#include "Core/IModule.h"
#include <string>

namespace Geek {
	class WindowConfig;
	class WindowModule : public IModule {
	public:

		void Startup() override;
		void Update(float deltaTime) override;
		void Shutdown() override;

	private:

	private:
		std::string m_apiType;
	};

}; //namespace Geek