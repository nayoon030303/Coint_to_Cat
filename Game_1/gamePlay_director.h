#pragma once
#include <vector>
using namespace std;

class GameAction
{
public:
	GameAction(int time, int type, int x, int y)
	{
		this->time = time;
		this->type = type;
		this->x = x;
		this->y = y;
	}

	int time;
	int type;
	int x;
	int y;
};

class GamePlay_Director
{
public:
	GamePlay_Director();
	void LoadAction(const char* filename);
	void Update();

	vector<GameAction> gameActions;

	int actionIndex;
	int actionTime;
};