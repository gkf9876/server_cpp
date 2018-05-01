﻿#include "MapManageService.h"

MapManageService::MapManageService()
{
}

MapManageService::~MapManageService()
{
}

void MapManageService::setMapDao(MapDao* mapDao)
{
	this->mapDao = mapDao;
}

void MapManageService::setMapInfoDao(MapInfoDao* mapInfoDao)
{
	this->mapInfoDao = mapInfoDao;
}

void MapManageService::setMonsterDao(MonsterDao* monsterDao)
{
	this->monsterDao = monsterDao;
}

void MapManageService::setDataSource(DataSource* dataSource)
{
	this->dataSource = dataSource;
}

void MapManageService::regenMonster()
{
	MYSQL connection = this->dataSource->getConnection();
	mysql_query(&connection, "BEGIN");

	try
	{
		list<Map> mapList = this->mapDao->getAll();
		list<Map>::iterator iter;
		int monster1Count;
		int monster2Count;
		int monster3Count;

		for (iter = mapList.begin(); iter != mapList.end(); iter++)
		{
			monster1Count = iter->getMonster1Count() - mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster1());
			monster2Count = iter->getMonster2Count() - mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster2());
			monster3Count = iter->getMonster3Count() - mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster3());

			if (monster1Count > 0)
			{
				for (int i = 0; i < monster1Count; i++)
				{
					Monster monster = monsterDao->get(iter->getMonster1());
					MapInfo monsterInfo;

					monsterInfo.setField(iter->getField());
					monsterInfo.setObjectCode(monster.getIdx());
					monsterInfo.setName(monster.getName());
					monsterInfo.setType("MONSTER");
					monsterInfo.setXpos(10);
					monsterInfo.setYpos(12);
					monsterInfo.setZOrder(1);
					monsterInfo.setFileDir(monster.getFileDir());
					monsterInfo.setCount(1);
					monsterInfo.setHp(monster.getHp());

					mapInfoDao->add(monsterInfo);
				}
			}

			if (monster2Count > 0)
			{
				for (int i = 0; i < monster2Count; i++)
				{
					Monster monster = monsterDao->get(iter->getMonster2());
					MapInfo monsterInfo;

					monsterInfo.setField(iter->getField());
					monsterInfo.setObjectCode(monster.getIdx());
					monsterInfo.setName(monster.getName());
					monsterInfo.setType("MONSTER");
					monsterInfo.setXpos(10);
					monsterInfo.setYpos(12);
					monsterInfo.setZOrder(1);
					monsterInfo.setFileDir(monster.getFileDir());
					monsterInfo.setCount(1);
					monsterInfo.setHp(monster.getHp());

					mapInfoDao->add(monsterInfo);
				}
			}

			if (monster3Count > 0)
			{
				for (int i = 0; i < monster3Count; i++)
				{
					Monster monster = monsterDao->get(iter->getMonster3());
					MapInfo monsterInfo;

					monsterInfo.setField(iter->getField());
					monsterInfo.setObjectCode(monster.getIdx());
					monsterInfo.setName(monster.getName());
					monsterInfo.setType("MONSTER");
					monsterInfo.setXpos(10);
					monsterInfo.setYpos(12);
					monsterInfo.setZOrder(1);
					monsterInfo.setFileDir(monster.getFileDir());
					monsterInfo.setCount(1);
					monsterInfo.setHp(monster.getHp());

					mapInfoDao->add(monsterInfo);
				}
			}
		}

		mysql_query(&connection, "COMMIT");
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
		mysql_query(&connection, "ROLLBACK");
	}
}

list<MapInfo> MapManageService::getFieldMonster(const char* field)
{
	return this->mapInfoDao->getFieldMonster(field);
}

list<MapInfo> MapManageService::getFieldObject(const char* field)
{
	return this->mapInfoDao->getFieldObject(field);
}

void MapManageService::addFieldMapInfo(MapInfo mapInfo)
{
	this->mapInfoDao->add(mapInfo);
}

MapInfo MapManageService::getMaxOrderItem(const char* field, int xpos, int ypos)
{
	return this->mapInfoDao->getMaxOrderItem(field, xpos, ypos);
}

list<MapInfo> MapManageService::getFieldItem(const char* field)
{
	return this->mapInfoDao->getFieldItem(field);
}

void MapManageService::deleteMaxOrderItem(const char* field, int xpos, int ypos)
{
	try
	{
		MapInfo maxOrderItem = mapInfoDao->getMaxOrderItem(field, xpos, ypos);

		if (strcmp(maxOrderItem.getName(), "nothing"))
			mapInfoDao->deleteMapInfo(maxOrderItem.getIdx(), maxOrderItem.getField());
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}