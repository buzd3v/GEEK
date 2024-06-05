#pragma once
#include "Singleton.h"

class Application;

namespace Geek {

class EngineLoop : public SingletonDclp<EngineLoop> {
public:
	EngineLoop();
	~EngineLoop();

private:
	//@brief internal variable
	bool b_isRunning;
	
	//Engine Module
	class GraphicModule* m_graphicModule;
	class WindowModule* m_windowModule;

private:
	void InitializeModule();
	void Run();
	void Startup();
	void Shutdown();

	friend class Application;
};

}  // namespace Geek
