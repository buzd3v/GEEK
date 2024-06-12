#include "GLFW/glfw3.h"
#include "GlfwWindow.h"
#include "Window/WindowConfig.h"
#include "Application.h"
void Geek::WindowAPI::GlfwWindow::CreateContext()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Geek::WindowAPI::GlfwWindow::CreateWindow()
{
	m_windowHandle = glfwCreateWindow(GET_CONFIG_VAR(WindowConfig, m_screenWidth),
		GET_CONFIG_VAR(WindowConfig, m_screenHeight),
		GET_CONFIG_VAR(WindowConfig, m_windowName).c_str(),
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
}

void Geek::WindowAPI::GlfwWindow::Shutdown()
{
	glfwDestroyWindow(m_windowHandle);
	m_windowHandle = nullptr;
	glfwTerminate();
}

