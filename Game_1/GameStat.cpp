#include "GameStat.h"
#include <cstring>
#include <iostream>
#include "global.h"



GameStat::GameStat()
{
	max = -1;
	isFile = true;
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
				&GameStat_player.id, &GameStat_player.name, 128, &GameStat_player.catKind, &GameStat_player.day, &GameStat_player.money, &GameStat_player.hp,
				&GameStat_player.coin1, &GameStat_player.coin2, &GameStat_player.coin3, &GameStat_player.coin4, &GameStat_player.time);

			playerInfos.push_back(GameStat_player);
			

		}
		fclose(fp);	//닫을 파일이 없으면 에러가 난다.
	}
	else
	{
		isFile = false;
		max = 0;
		Save();
		isFile = true;
	}

}

void GameStat::Save()
{
	FILE* fp = nullptr;
	fopen_s(&fp, "Gamedata.dat", "wt");

	
	if (isFile &&player->GetId() == -1)
		max += 1;
	fprintf(fp, "%d \n", max);


	for (int i = 0; i < playerInfos.size(); i++)
	{
		if (playerInfos[i].id == player->GetId())
		{
			playerInfos[i].day = player->GetDay();
			playerInfos[i].money = player->GetMoney();
			playerInfos[i].hp = player->GetHp();
			playerInfos[i].coin1 = player->GetCoin1();
			playerInfos[i].coin2 = player->GetCoin1();
			playerInfos[i].coin3 = player->GetCoin3();
			playerInfos[i].coin4 = player->GetCoin4();
			playerInfos[i].time = player->GetTime();
		}

		
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
