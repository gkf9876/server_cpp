#include "LoadingScreen.h"

LoadingScreen::LoadingScreen()
{
}

LoadingScreen::~LoadingScreen()
{
}

void LoadingScreen::setIdx(int idx)
{
	this->idx = idx;
}

int LoadingScreen::getIdx()
{
	return this->idx;
}

void LoadingScreen::setName(const char * name)
{
	strcpy(this->name, name);
}

const char * LoadingScreen::getName()
{
	return this->name;
}

void LoadingScreen::setFilePath(const char * filePath)
{
	strcpy(this->filePath, filePath);
}

const char * LoadingScreen::getFilePath()
{
	return this->filePath;
}
