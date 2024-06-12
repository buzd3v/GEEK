#pragma once

#include "Core/IModule.h"

namespace Geek {
	class InputModule : public IModule
	{
	public:
		InputModule() = default;
		~InputModule() = default;

		// Inherited via IModule
		void Startup() override;
		void Update(float deltaTime) override;
		void Shutdown() override;

	};
};