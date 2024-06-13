#include "Application.h"
#include "EngineLoop.h"

#include "vld.h"

void Geek::Application::Start()
{
	if (EngineLoop::GetInstance() == nullptr)
	{
		EngineLoop::Construct();
	}

	if (EngineLoop::GetInstance()->b_isRunning)
	{
		EngineLoop::GetInstance()->Run();
	}
}

void Geek::Application::Exit()
{
	EngineLoop::GetInstance()->b_isRunning = false;
}