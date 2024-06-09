#pragma once

namespace Geek {
	namespace WindowAPI {

		enum class WindowType {
			FullScreen,
			Windowed,
			NoBorder,
			KeepResolution,
		};

		class IWindowAPI
		{
		protected:
			WindowType m_windowType;
			int m_width, m_height;

		public:
			IWindowAPI() : m_width(0), m_height(0), m_windowType(WindowType::FullScreen) {

			}

			virtual void CreateContext() {};
			virtual void InitProperty(WindowType type, int width, int height) {};
			virtual void CreateWindow() {};
			virtual void Shutdown() {};
		};



	};// namespace WindowAPI
};// namespace Geek


