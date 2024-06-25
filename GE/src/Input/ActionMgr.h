#pragma once

#include "Action.h"
#include "Core/ConfigMgr.h"
#include "Core/Delegate.h"

namespace Geek
{
	class ActionMgr : public ConfigMgr<Action>
	{
	private:
		ActionMgr(std::string filePath, std::string rootNodeName) : ConfigMgr<Action>(filePath, rootNodeName) {
			
		}
	public:
		//connect each  
		void Connect(std::string actionName, Callback<> callback);
		void Disconnect(std::string actionName);
		void Invoke();
	};

}