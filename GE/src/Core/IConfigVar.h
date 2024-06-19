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
	node =  root.child(#varName);										\
	if (!node) {																										\
		std::cout << "Error accessing " << #varName << " node element!" << std::endl;		\
		return;																												\
	 }																															\
	b_##varName = node.text().as_##type();													\

#define SET_CONFIG_VAR_STR(varName)															\
	node = root.child(#varName);										\
	if (!node) {																										\
		std::cout << "Error accessing " << #varName << " node element!" << std::endl;		\
		return;																												\
	 }																															\
	std::string varName = node.text().as_string();													\

#define GET_CONFIG_VAR(config, variable) config.variable				
		
#define GET_CONFIG(classMgrName, configName)		classMgrName::GetInstance()->FindConfig(configName)
	class IConfigVar {
	protected:
		std::string m_configName;
		pugi::xml_node node;
	public:
		virtual void BindToConfig(pugi::xml_node& root) = 0;
		std::string GetName() { return m_configName; }
	};
	
};

