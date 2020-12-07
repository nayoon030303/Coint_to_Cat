#pragma once
#include "Player.h"

class GameStat
{
public:
	GameStat();
	void Load();
	void Save();

	bool isFile;
	int max;
	Player GameStat_player;
	int GetMax() { return max; }

};


