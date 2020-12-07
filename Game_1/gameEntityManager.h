#pragma once
#include <vector>
#include "runPlayer.h"
#include "musicPlayer.h"
using namespace std;

class Enemy;
class MusicDirections;

class GameEntityManager
{
public:
	vector<Enemy*> enemies;//run
	vector< MusicDirections*> directions;

	RunPlayer* runPlayer;
	MusicPlayer* musicPlayer;

	GameEntityManager();
	
	void Render();
	void Update();
	void ClearAll();

	void AddEnemy(int type, int x);
	void runStageUpdate();
	void runStageRender();

	void AddDirections(int type);
	void musicStageUpdate();
	void musicStageRender();
	void music_keyState();


	void setIsRunStage(bool isRun) { isRunStage = isRun; }
	bool getIsRunStage() { return isRunStage; }
	void setIsMusicStage(bool isDirection) { isMusicStage = isDirection; }
	bool getIsMusicStage() { return isMusicStage; }

	bool isRunStage;
	bool isMusicStage;

	bool isLeft;
	bool isRight;
	bool isUp;
	bool isDown;
	bool isSpace;

	bool isGood;
	bool isMiss;

	int enemyCount;
	int time;
	int m_time1;
	int m_time2;
	int m_time3;
	int scoreTime;
	int enemySpeed;
	int timeMax;

	enum direction_Type
	{
		left = 0,
		up,
		space,
		down,
		right

	};

};