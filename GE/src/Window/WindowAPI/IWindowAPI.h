#pragma once

namespace Geek {
namespace WindowAPI {
	
	class IWindowAPI
	{
	protected:
		enum class WindowType {
			FullScreen,
			Windowed,
			NoBorder,
			KeepResolution,
		};
	private:

	public:
		virtual void CreateContext() = 0;
		virtual void CreateWindow() = 0;
	};



};// namespace WindowAPI
};// namespace Geek


