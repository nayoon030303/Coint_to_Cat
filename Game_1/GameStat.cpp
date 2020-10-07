#include "GameStat.h"
#include <cstring>
#include <iostream>
#include "global.h"



GameStat::GameStat()
{
	max = -1;
}

void GameStat::Load()
{
	FILE* fp = nullptr;

	fopen_s(&fp, "Gamedata.dat", "rt");

	if (fp != nullptr)
	{

		fscanf_s(fp, "%d ",&max);
		
		for (int i = 0; i <max; i++)
		{
		
			fscanf_s(fp, "%d %s %d %d %d %d %d %d %d %d %d",
				&player.id, &player.name, 128, &player.catKind, &player.day, &player.money, &player.hp,
				&player.coin1, &player.coin2, &player.coin3, &player.coin4, &player.time);

			playerInfos.push_back(player);
			

		}
		fclose(fp);	//닫을 파일이 없으면 에러가 난다.
	}
	else
	{
		Save();
	}

}

void GameStat::Save()
{
	FILE* fp = nullptr;
	fopen_s(&fp, "Gamedata.dat", "wt");

	max += 1;
	fprintf(fp, "%d \n", max);

	for (int i = 0; i < playerInfos.size(); i++)
	{
		fprintf(fp, "%d %s %d %d %d %d %d %d %d %d %d\n",
			playerInfos[i].id,
			playerInfos[i].name,
			playerInfos[i].catKind,
			playerInfos[i].day,
			playerInfos[i].money,
			playerInfos[i].hp,
			playerInfos[i].coin1,
			playerInfos[i].coin2,
			playerInfos[i].coin3,
			playerInfos[i].coin4,
			playerInfos[i].time
		);
	}

	fclose(fp);
}
