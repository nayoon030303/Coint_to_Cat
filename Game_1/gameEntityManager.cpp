#include "gameEntityManager.h"
#include "runEnemy_1.h"
#include "enemy.h"
#include "runEnemy_1.h"

GameEntityManager::GameEntityManager()
{
	time = 0;
}

void GameEntityManager::AddEnemy(int type,int x)
{

	if (type == 1) {
		Enemy* enemy = new RunEnemy_1();	//
		x = 1280;
		enemy->setPosX(x);
	
		enemies.push_back(enemy);
	}
	else if (type == 2) {
		Enemy* Enemy = new RunEnemy_1;
		x = 1;
	}
}

void GameEntityManager::Update()
{	
	time += 1;
	if (time >= 100) {
		AddEnemy(1,1280);
		time = 0;
	}
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->Update();
	}
}

void GameEntityManager::Render()
{
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->Render();
	}
}