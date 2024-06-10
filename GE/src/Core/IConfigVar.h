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

	class IConfigVar {
	
	protected:
		std::string m_filePath;

		//for read xml data
		pugi::xml_node root;
		pugi::xml_document *doc;
		pugi::xml_node node;
	
	public:
		virtual void ReadData()
		{
			doc = new pugi::xml_document();
			pugi::xml_parse_result result = doc->load_file(m_filePath.c_str());
			if (!result) {
				std::cout << "Error loading XML file: " << result.description() << std::endl;
				return;
			}

			// Access the root element
			root = (doc->child("Config"));
			if (root == nullptr) {
				std::cout << "Error accessing root element!" << std::endl;
			}
		}
		virtual void BindToConfig() = 0;
	};
	
};

