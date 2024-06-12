#pragma once
#include "Core/IConfigVar.h"

namespace Geek
{
	class ActionConfig : public IConfigVar
	{
		// Inherited via IConfigVar
		void BindToConfig() override;


	};
} // namespace Geek