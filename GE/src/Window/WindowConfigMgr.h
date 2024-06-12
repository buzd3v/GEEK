#pragma once

#include "WindowConfig.h"
#include "Core/IConfigMgr.h"

namespace Geek
{
	class WindowConfigMgr : public IConfigMgr, SingletonDclp<WindowConfigMgr>
	{
	public:
		WindowConfigMgr(std::string filePath, std::string rootNodeName);

		// Inherited via IConfigMgr
		void AddToConfigList() override;
		void FindConfig(std::string configName) override;
	};
} // namespace Geek