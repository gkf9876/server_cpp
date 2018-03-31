#include "Chatting.h"

Chatting::Chatting()
{
}

Chatting::~Chatting()
{
}

void Chatting::setIdx(int idx)
{
	this->idx = idx;
}

int Chatting::getIdx()
{
	return this->idx;
}

void Chatting::setInputdate(const char* inputdate)
{
	strcpy(this->inputdate, inputdate);
}

const char* Chatting::getInputdate()
{
	return this->inputdate;
}

void Chatting::setName(const char* name)
{
	strcpy(this->name, name);
}

const char* Chatting::getName()
{
	return this->name;
}

void Chatting::setContent(const char* content)
{
	strcpy(this->content, content);
}

const char* Chatting::getContent()
{
	return this->content;
}

void Chatting::setField(const char* field)
{
	strcpy(this->field, field);
}

const char* Chatting::getField()
{
	return this->field;
}