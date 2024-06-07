#include "GlfwWindow.h"
#include "GLFW/glfw3.h"

void Geek::WindowAPI::GlfwWindow::CreateContext()
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Geek::WindowAPI::GlfwWindow::CreateWindow()
{
  GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
  if (window == NULL)
  {
    //std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    //return -1;
  }
  glfwMakeContextCurrent(window);
}
