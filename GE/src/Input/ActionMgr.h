#pragma once

#include "Core/ConfigMgr.h"
#include "Action.h"
#include <functional>

namespace Geek
{
	class ActionMgr : public ConfigMgr<Action>
	{
	public:
		template <typename T>
		void Connect(std::string actionName, std::function<T> callback);
		void Excute(std::string actionName);
	};

	template<typename T>
	inline void ActionMgr::Connect(std::string actionName, std::function<T> callback)
	{
	}
}