#pragma once

#include "WindowConfig.h"
#include "Core/IConfigMgr.h"

namespace Geek
{
	class WindowConfigMgr : public IConfigMgr, SingletonDclp<WindowConfigMgr>
	{
	public:
		WindowConfigMgr(std::string filePath);

		// Inherited via IConfigMgr
		void AddToConfigList() override;
		void FindConfig(std::string configName) override;
	};
} // namespace Geek