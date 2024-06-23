#include "GLFW/glfw3.h"
#include "KeyCode.h"

namespace Geek
{
	class GLFWInput
	{
		static uint16_t RegisterKeyCallback(Callback<void, GLFWwindow*, int, int, int, int> callback);
		static void UnregisteredkeyCallback()
	};
}


//TODO: READ_THIS -> for more ref read this https://isetta.io/blogs/week-3/#input-module 