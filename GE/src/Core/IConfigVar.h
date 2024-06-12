#pragma once

#include <string>
#include <pugixml.hpp>
#include <iostream>
namespace Geek {
#define SET_CONFIG_VAR(varName, type)															\
	node = root.child(#varName);										\
	if (!node) {																										\
		std::cout << "Error accessing " << #varName << " node element!" << std::endl;		\
		return;																												\
	 }																															\
	m_##varName = node.text().as_##type();													\

#define SET_CONFIG_B_VAR(varName, type)															\
	node = root.child(#varName);										\
	if (!node) {																										\
		std::cout << "Error accessing " << #varName << " node element!" << std::endl;		\
		return;																												\
	 }																															\
	b_##varName = node.text().as_##type();													\

#define GET_CONFIG_VAR(className, variable)		className::GetInstance()->variable						
		

	class IConfigVar {
	public:
		virtual void BindToConfig() = 0;
	};
	
};

