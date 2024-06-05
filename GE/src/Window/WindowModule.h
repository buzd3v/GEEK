#pragma once
#include "Core/IModule.h"

namespace Geek {

	class WindowModule : public IModule {
	public:
		void Startup() override;
		void Update(float deltaTime) override;
		void Shutdown() override;

	private:
	};

}; //namespace Geek