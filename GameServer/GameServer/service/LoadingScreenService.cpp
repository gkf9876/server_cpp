#include "LoadingScreenService.h"

LoadingScreenService::LoadingScreenService()
{
}

LoadingScreenService::~LoadingScreenService()
{
}

void LoadingScreenService::setLoadingScreenDao(LoadingScreenDao* loadingScreenDao)
{
	this->loadingScreenDao = loadingScreenDao;
}