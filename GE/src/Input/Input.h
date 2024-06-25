#pragma once

#include "Core/Alias.h"
#include "KeyCode.h"

namespace Geek
{
	class Input
	{
	public:


		static void RegisterMousePressCallback(MouseButton button, Callback<>& callback);
		static void RegisterMouseReleaseCallback(MouseButton button, Callback<>& callback);

		static u64 RegisterKeyPressCallback(KeyCode key, Callback<>& callback);
		static u64 RegisterKeyReleaseCallback(KeyCode key, Callback<>& callback);

	};
}