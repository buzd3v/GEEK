#pragma once

#include "Core/ConfigMgr.h"
#include "Action.h"
#include <functional>

namespace Geek
{
	class ActionMgr : public ConfigMgr<IAction>
	{
	private:

	public:
		template<typename T, typename... args>
		void Connect(std::string actionName, Callback<T(args...)> callback);
		void Disconnect(std::string actionName); 
	};
	
}