#pragma once

#include "Core/ConfigMgr.h"
#include "ActionConfig.h"
#include <functional>

namespace Geek
{
	class ActionMgr : public ConfigMgr<ActionConfig>
	{
	public:
		template <typename T>
		void Connect(std::string actionName, std::function<T> callback);
		void Trigger(std::string actionName);
	};

	template<typename T>
	inline void ActionMgr::Connect(std::string actionName, std::function<T> callback)
	{
	}
}