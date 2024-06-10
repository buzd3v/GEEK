#include "GLFW/glfw3.h"
#include "GlfwWindow.h"


void Geek::WindowAPI::GlfwWindow::CreateContext()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Geek::WindowAPI::GlfwWindow::CreateWindow()
{
	m_windowHandle = glfwCreateWindow(m_width, m_height, "LearnOpenGL", NULL, NULL);
	if (m_windowHandle == NULL)
	{
		//std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		//return -1;
	}
	glfwMakeContextCurrent(m_windowHandle);
}

void Geek::WindowAPI::GlfwWindow::Shutdown()
{
}

void Geek::WindowAPI::GlfwWindow::InitProperty(WindowType type, int width, int height)
{
	m_height = height;
	m_width = width;
	m_windowType = type;
}

