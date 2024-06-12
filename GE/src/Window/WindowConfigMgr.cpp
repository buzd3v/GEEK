#include "WindowConfigMgr.h"

Geek::WindowConfigMgr::WindowConfigMgr(std::string filePath)
{
	m_filePath = filePath;
	IConfigMgr::ReadData();
	AddToConfigList();
}

void Geek::WindowConfigMgr::AddToConfigList()
{
	
}

void Geek::WindowConfigMgr::FindConfig(std::string configName)
{
}
