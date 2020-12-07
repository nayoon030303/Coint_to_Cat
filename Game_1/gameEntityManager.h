#pragma once
#include <vector>
#include "runPlayer.h"
using namespace std;

class Enemy;

class GameEntityManager
{
public:
	vector<Enemy*> enemies;
	//Player* player;
	RunPlayer* runPlayer;


	GameEntityManager();
	void AddEnemy(int type, int x);
	void Render();
	void Update();
	void ClearAll();
	void runStageUpdate();
	void runStageRender();
	void directionUpdate();
	void directionRender();

	void setIsRunStage(bool isRun) { isRunStage = isRun; }
	bool getIsRunStage() { return isRunStage; }
	void setIsDirectionStage(bool isDirection) { isDirectionStage = isDirection; }
	bool getIsDirectionStage() { return isDirectionStage; }

	bool isRunStage;
	bool isDirectionStage;


	int enemyCount;
	int time;
	int scoreTime;
	int enemySpeed;
	int timeMax;

};