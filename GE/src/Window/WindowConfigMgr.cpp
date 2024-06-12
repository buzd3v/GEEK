#include "WindowConfigMgr.h"

Geek::WindowConfigMgr::WindowConfigMgr(std::string filePath, std::string rootNodeName)
{
	m_filePath = filePath;
	m_rootNodeName = rootNodeName;
	IConfigMgr::ReadData();
	AddToConfigList();
}

void Geek::WindowConfigMgr::AddToConfigList()
{
	while (firstChild != nullptr)
	{
		WindowConfig config;
		config.BindToConfig(firstChild);
		m_listConfig.push_back(config); // TODO: add rule of file for all class to avoid dangling
		firstChild = firstChild.next_sibling();
	}
}

void Geek::WindowConfigMgr::FindConfig(std::string configName)
{
}
