#pragma once
#include "Core/IConfigVar.h"

namespace Geek
{
	class ActionConfig : public IConfigVar
	{
	public:
		// Inherited via IConfigVar
		void BindToConfig(pugi::xml_node& root) override;
	};
} // namespace Geek