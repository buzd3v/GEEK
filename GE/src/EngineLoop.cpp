#include "EngineLoop.h"

#include "Window/WindowModule.h"

Geek::EngineLoop::EngineLoop()
{
	InitializeModule();
}

Geek::EngineLoop::~EngineLoop() {}

void
Geek::EngineLoop::InitializeModule()
{
	m_windowModule = new WindowModule();
}

void
Geek::EngineLoop::Run()
{
	Startup();
	while (b_isRunning) {
		Update();
	}
	Shutdown();
}

void
Geek::EngineLoop::Update()
{
	float deltaTime = 0.1;
	m_windowModule->Update(deltaTime);
}

void
Geek::EngineLoop::Startup()
{
	m_windowModule->Startup();
}

void
Geek::EngineLoop::Shutdown()
{
	m_windowModule->Shutdown();

	delete m_windowModule;

	//self calling destruct
	EngineLoop::Destruct();
}
