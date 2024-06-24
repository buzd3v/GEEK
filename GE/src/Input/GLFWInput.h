#include "GLFW/glfw3.h"
#include "KeyCode.h"
#include "Core/Alias.h"

namespace Geek
{
	class GLFWInput
	{
		static uint16_t RegisterKeyCallback(Callback<GLFWwindow*, int, int, int, int> callback);
		static void UnregisteredKeyCallback(); //
	};
}


//TODO: READ_THIS -> for more ref read this https://isetta.io/blogs/week-3/#input-module 
// Due to the doc, there's no way to compare two callback is the same so do need an delegate to bind and unbind 