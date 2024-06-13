#include "GLFW/glfw3.h"
#include "GlfwWindow.h"
#include "Window/WindowConfig.h"
#include "Application.h"
#include "Core/ConfigMgr.h"
void Geek::WindowAPI::GlfwWindow::CreateContext()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Geek::WindowAPI::GlfwWindow::CreateWindow()
{
	WindowConfig config = GET_CONFIG(ConfigMgr<WindowConfig>, "WindowSetting");

	m_windowHandle = glfwCreateWindow(GET_CONFIG_VAR(config, m_screenWidth),
																		GET_CONFIG_VAR(config, m_screenHeight),
																		GET_CONFIG_VAR(config, m_windowName).c_str(),
																		NULL, NULL); 
	if (m_windowHandle == NULL)
	{
		glfwTerminate();
	}
	glfwMakeContextCurrent(m_windowHandle);
}

void Geek::WindowAPI::GlfwWindow::Update(float deltaTime)
{
	if (glfwWindowShouldClose(m_windowHandle))
	{
		Application::Exit();
	}
	glfwSwapBuffers(m_windowHandle);
	glfwPollEvents();
}

void Geek::WindowAPI::GlfwWindow::Shutdown()
{
	glfwDestroyWindow(m_windowHandle);
	m_windowHandle = nullptr;
	glfwTerminate();
}

