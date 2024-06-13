#include "Window/WindowConfig.h"
#include "WindowAPI/IWindowAPI.h"
#include "WindowModule.h"
#include "Core/ConfigMgr.h"
using namespace Geek::WindowAPI;

void Geek::WindowModule::Startup()
{
	ConfigMgr<WindowConfig>::GetInstance()->Construct("WindowConfig.xml", "Config");
	auto c = ConfigMgr<WindowConfig>::GetInstance();
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
	m_window = nullptr;
}
