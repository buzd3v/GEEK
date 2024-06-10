#include "Window/WindowConfig.h"
#include "WindowAPI/IWindowAPI.h"
#include "WindowModule.h"
using namespace Geek::WindowAPI;

void Geek::WindowModule::Startup()
{
	WindowConfig::GetInstance()->Construct("WindowConfig.xml");
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

}
