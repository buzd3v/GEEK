#pragma once

#include <pugixml.hpp>
#include <iostream>
#include <unordered_map>

#include "IConfigVar.h"
#include <sid.h>
#include <Singleton.h>

namespace Geek //TODO: consider dynamic alloc or not 
{
	template<typename ConfigVar, typename = std::enable_if_t<std::is_base_of<IConfigVar, ConfigVar>::value>> //only allows for class derived from IConfigVar
	class ConfigMgr : public SingletonDclp<ConfigMgr<ConfigVar>>  // TODO: Make this as template because it will be the same for all class config
	{
	private:
		std::string m_filePath;

		//for read xml data
		pugi::xml_document* doc;
		pugi::xml_node m_root;
		pugi::xml_node m_firstChild;
		std::string m_rootNodeName;
		
	protected:
		//store config
		std::unordered_map<StringId, ConfigVar> m_listConfig;
	public:
		ConfigMgr(std::string filePath, std::string rootNodeName) : m_filePath(filePath), m_rootNodeName(rootNodeName)
		{
			ReadData();
			AddToConfigList();
		}

		void ReadData()
		{
			doc = new pugi::xml_document();
			pugi::xml_parse_result result = doc->load_file(m_filePath.c_str());
			if (!result) {
				std::cout << "Error loading XML file: " << result.description() << std::endl; //TODO: Make a logging class to write log to file when enable a define like #ifdef LOGGING
				return;
			}

			// Access the root element
			m_root = (doc->child(m_rootNodeName.c_str()));
			if (m_root == nullptr) {
				std::cout << "Error accessing root element!" << std::endl;
			}

			m_firstChild = m_root.first_child();
			if (m_firstChild == nullptr)
			{
				std::cout << "Cannot find child" << std::endl;
			}

		}

		~ConfigMgr()
		{
			//doc->reset();
			delete doc;
		}

		void AddToConfigList()
		{
			while (m_firstChild != NULL)
			{
				ConfigVar config;
				config.BindToConfig(m_firstChild);
				m_listConfig.insert(std::make_pair(SID(config.GetName().c_str()), config));
				m_firstChild = m_firstChild.next_sibling();
			}
		}
		ConfigVar FindConfig(std::string configName)
		{
			auto value = m_listConfig.find(SID(configName.c_str()));
			if (value != m_listConfig.end())
			{
				return value->second;
			}
			else return ConfigVar();
		}
	};
};
