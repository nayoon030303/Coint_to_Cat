#include "gamePlay_director.h"
#include <iostream>
#include <fstream>
#include <string.h>

GamePlay_Director::GamePlay_Director()
{
	actionIndex = 0;
	actionTime = 0;
}

void GamePlay_Director::LoadAction(const char* filename)
{
	int time;
	int type;
	int x, y;
	string comment;

	ifstream fin;//입력 클래스
	fin.open(filename);

	while (fin >> time >> type >> x >> y >> comment) 
	{
		GameAction action(time, type, x, y);
		gameActions.push_back(action);
	}

	fin.close();
}

void GamePlay_Director::Update()
{

}

