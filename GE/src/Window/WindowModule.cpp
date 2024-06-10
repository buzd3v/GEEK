#include "WindowAPI/IWindowAPI.h"
#include "WindowModule.h"
#include "Window/WindowConfig.h"
using namespace Geek::WindowAPI;

void Geek::WindowModule::Startup()
{
	WindowConfig::GetInstance()->Construct("WindowConfig.xml");
}

void Geek::WindowModule::Update(float deltaTime)
{
}

void Geek::WindowModule::Shutdown()
{
}
