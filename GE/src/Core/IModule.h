#pragma once
#include <Singleton.h>
namespace Geek {
	class IModule 
	{
	public: 
		virtual void Startup() = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void Shutdown() = 0;
	};
}; //namespace Geek
