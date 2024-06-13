#include "Window/WindowConfig.h"
#include "WindowAPI/IWindowAPI.h"
#include "WindowModule.h"
#include "Core/ConfigMgr.h"
using namespace Geek::WindowAPI;

void Geek::WindowModule::Startup()
{
	ConfigMgr<WindowConfig>::GetInstance()->Construct("WindowConfig.xml", "Config");
	m_window = new GlfwWindow();
	m_window->CreateContext();
	m_window->CreateWindow();
}

void Geek::WindowModule::Update(float deltaTime)
{
	m_window->Update(deltaTime);
}

void Geek::WindowModule::Shutdown()
{
	m_window->Shutdown();
	delete m_window;
	ConfigMgr<WindowConfig>::GetInstance()->Destruct();
}
