#pragma once
#include <vector>
using namespace std;

class Enemy;

class GameEntityManager
{
public:
	vector<Enemy*> enemies;

	GameEntityManager();
	void AddEnemy(int type, int x);
	void Render();
	void Update();

	int time;

};