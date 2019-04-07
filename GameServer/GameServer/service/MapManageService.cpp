#include "MapManageService.h"

MapManageService::MapManageService()
{
	srand(time(NULL));
}

MapManageService::~MapManageService()
{
	mapData.clear();
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

list<MapInfo> MapManageService::regenMonster()
{
	MYSQL connection = this->dataSource->getConnection();
	mysql_query(&connection, "BEGIN");

	try
	{
		list<Map> mapList = this->mapDao->getAll();
		list<Map>::iterator iter;
		list<MapInfo> regenMonster;
		int monster1Count;
		int monster2Count;
		int monster3Count;
		int xpos;
		int ypos;

		for (iter = mapList.begin(); iter != mapList.end(); iter++)
		{
			TMXTileLayer* metaInfoLayer = mapData[iter->getField()]->getTMXTileLayer(iter->getField(), "MetaInfo");
			TMXTileLayer* backgroundLayer = mapData[iter->getField()]->getTMXTileLayer(iter->getField(), "Background");
			std::vector<std::vector<unsigned int>> metaInfoTileVector = metaInfoLayer->getTileVector();
			std::vector<std::vector<unsigned int>> backgroundTileVector = backgroundLayer->getTileVector();

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
					monsterInfo.setZOrder(1);
					monsterInfo.setFileDir(monster.getFileDir());
					monsterInfo.setCount(1);
					monsterInfo.setHp(monster.getHp());

					xpos = rand() % metaInfoLayer->getWidth();
					ypos = rand() % metaInfoLayer->getHeight();

					if (backgroundTileVector[ypos][xpos] == 130 && metaInfoTileVector[ypos][xpos] == 0)
					{
						monsterInfo.setXpos(xpos);
						monsterInfo.setYpos(metaInfoLayer->getHeight() - (ypos + 1));
						monsterInfo.setSeeDirection(26 + rand() % 4);
						monsterInfo.setAction(0);
						mapInfoDao->add(monsterInfo);
						regenMonster.push_back(monsterInfo);
					}
					else
						i--;
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
					monsterInfo.setZOrder(1);
					monsterInfo.setFileDir(monster.getFileDir());
					monsterInfo.setCount(1);
					monsterInfo.setHp(monster.getHp());

					xpos = rand() % metaInfoLayer->getWidth();
					ypos = rand() % metaInfoLayer->getHeight();

					if (backgroundTileVector[ypos][xpos] == 130 && metaInfoTileVector[ypos][xpos] == 0)
					{
						monsterInfo.setXpos(xpos);
						monsterInfo.setYpos(metaInfoLayer->getHeight() - (ypos + 1));
						monsterInfo.setSeeDirection(26 + rand() % 4);
						monsterInfo.setAction(0);
						mapInfoDao->add(monsterInfo);
						regenMonster.push_back(monsterInfo);
					}
					else
						i--;
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
					monsterInfo.setZOrder(1);
					monsterInfo.setFileDir(monster.getFileDir());
					monsterInfo.setCount(1);
					monsterInfo.setHp(monster.getHp());

					xpos = rand() % metaInfoLayer->getWidth();
					ypos = rand() % metaInfoLayer->getHeight();

					if (backgroundTileVector[ypos][xpos] == 130 && metaInfoTileVector[ypos][xpos] == 0)
					{
						monsterInfo.setXpos(xpos);
						monsterInfo.setYpos(metaInfoLayer->getHeight() - (ypos + 1));
						monsterInfo.setSeeDirection(26 + rand() % 4);
						monsterInfo.setAction(0);
						mapInfoDao->add(monsterInfo);
						regenMonster.push_back(monsterInfo);
					}
					else
						i--;
				}
			}
		}

		mysql_query(&connection, "COMMIT");
		return regenMonster;
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

void MapManageService::loadTMXData()
{
	try
	{
		list<Map> mapList = this->mapDao->getAll();
		list<Map>::iterator iter;

		for (iter = mapList.begin(); iter != mapList.end(); iter++)
		{
			char fileDir[1024];
			sprintf(fileDir, "Resources/%s", iter->getField());

			TMXLoader* loader = new TMXLoader();
			loader->loadMap(iter->getField(), fileDir);

			mapData[iter->getField()] = loader;
		}
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

std::map<std::string, TMXLoader*> MapManageService::getMapData()
{
	return this->mapData;
}

list<MapInfo> MapManageService::moveMonsters()
{
	MYSQL connection = this->dataSource->getConnection();
	mysql_query(&connection, "BEGIN");

	try
	{
		list<Map> mapList = mapDao->getAll();
		list<Map>::iterator iter;
		list<MapInfo> moveMonsters;

		for (iter = mapList.begin(); iter != mapList.end(); iter++)
		{
			TMXTileLayer* metaInfoLayer = mapData[iter->getField()]->getTMXTileLayer(iter->getField(), "MetaInfo");
			TMXTileLayer* backgroundLayer = mapData[iter->getField()]->getTMXTileLayer(iter->getField(), "Background");
			std::vector<std::vector<unsigned int>> metaInfoTileVector = metaInfoLayer->getTileVector();
			std::vector<std::vector<unsigned int>> backgroundTileVector = backgroundLayer->getTileVector();

			list<MapInfo> moveFieldMonsters = mapInfoDao->getFieldMonster(iter->getField());
			list<MapInfo>::iterator monsterIter;

			for (monsterIter = moveFieldMonsters.begin(); monsterIter != moveFieldMonsters.end();)
			{
				int xpos = monsterIter->getXpos();
				int ypos = metaInfoLayer->getHeight() - (monsterIter->getYpos() + 1);
				int move = rand() % 4;
				switch (move)
				{
				case 0:
					xpos += 1;
					monsterIter->setSeeDirection(27);
					break;
				case 1:
					xpos -= 1;
					monsterIter->setSeeDirection(26);
					break;
				case 2:
					ypos += 1;
					monsterIter->setSeeDirection(28);
					break;
				case 3:
					ypos -= 1;
					monsterIter->setSeeDirection(29);
					break;
				}

				if (backgroundTileVector[ypos][xpos] == 130 && metaInfoTileVector[ypos][xpos] == 0)
				{
					monsterIter->setXpos(xpos);
					monsterIter->setYpos(metaInfoLayer->getHeight() - (ypos + 1));
					moveMonsters.push_back(*monsterIter);
				}
				else
					continue;

				mapInfoDao->updatePosition(monsterIter->getIdx(), monsterIter->getXpos(), monsterIter->getYpos(), monsterIter->getSeeDirection());
				monsterIter++;
			}
		}

		mysql_query(&connection, "COMMIT");
		return moveMonsters;
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
		mysql_query(&connection, "ROLLBACK");
	}
}
