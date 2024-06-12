#pragma once

#include <pugixml.hpp>
#include <iostream>
#include <vector>

#include "IConfigVar.h"

namespace Geek
{
	class IConfigMgr
	{
	protected:
		std::string m_filePath;

		//for read xml data
		pugi::xml_document* doc;
		pugi::xml_node root;
		pugi::xml_node firstChild;
		pugi::xml_node node;

		std::vector<IConfigVar> m_listConfig;
		std::string m_rootNodeName;

	public:
		void ReadData()
		{
			doc = new pugi::xml_document();
			pugi::xml_parse_result result = doc->load_file(m_filePath.c_str());
			if (!result) {
				std::cout << "Error loading XML file: " << result.description() << std::endl;
				return;
			}

			// Access the root element
			root = (doc->child(m_rootNodeName.c_str()));
			if (root == nullptr) {
				std::cout << "Error accessing root element!" << std::endl;
			}

			firstChild = root.first_child();
			if (firstChild == nullptr)
			{
				std::cout << "Cannot find child" << std::endl;
			}

		}

		virtual void AddToConfigList() = 0;
		virtual void FindConfig(std::string configName) = 0;
	};
};
