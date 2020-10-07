#pragma once
#include "Player.h"

class GameStat
{
public:
	GameStat();
	void Load();
	void Save();

	int max;
	Player player;
	int GetMax() { return max; }

};