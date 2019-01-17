#include "ServerInfoService.h"

ServerInfoService::ServerInfoService()
{

}

ServerInfoService::~ServerInfoService()
{

}

void ServerInfoService::setServerInfoDao(ServerInfoDao* serverInfoDao)
{
	this->serverInfoDao = serverInfoDao;
}

ServerInfo ServerInfoService::getServerInfo(int idx)
{
	return this->serverInfoDao->get(idx);
}

void ServerInfoService::updateServerInfo(ServerInfo serverInfo)
{
	this->serverInfoDao->update(serverInfo);
}