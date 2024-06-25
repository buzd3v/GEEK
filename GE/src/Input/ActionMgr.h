#pragma once

#include "Action.h"
#include "Core/ConfigMgr.h"
#include "Core/Delegate.h"

namespace Geek
{
	class ActionMgr : public ConfigMgr<Action>
	{
	private:

	public:

		//connect each  
		template<typename... args>
		void Connect(std::string actionName, Callback<args ... > callback);

		void Disconnect(std::string actionName);

		template <typename ...args>
		void Invoke(args ...);
	};

}