#include "MapManageService.h"

MapManageService::MapManageService(DataSource* dataSource)
{
	this->dataSource = dataSource;
	this->mapDao = new MapDao(dataSource);
	this->mapInfoDao = new MapInfoDao(dataSource);
	this->monsterDao = new MonsterDao(dataSource);
}

MapManageService::~MapManageService()
{
	delete this->mapDao;
	delete this->mapInfoDao;
	delete this->monsterDao;
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