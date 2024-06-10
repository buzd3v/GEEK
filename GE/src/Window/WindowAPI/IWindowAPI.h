#pragma once
#include <string>
namespace Geek {
	namespace WindowAPI {

		class IWindowAPI
		{
		protected:

		public:
			virtual void CreateContext() = 0;
			virtual void CreateWindow() = 0;
			virtual void Shutdown() = 0;
		};
	};// namespace WindowAPI
};// namespace Geek


