#pragma once
#include "Core/IConfigVar.h"
#include "KeyCode.h"
namespace Geek
{
	class ActionConfig : public IConfigVar
	{

	private:
		bool m_bIsSingle;
		

	public:
		// Inherited via IConfigVar
		void BindToConfig(pugi::xml_node& root) override;
	};
} // namespace Geek