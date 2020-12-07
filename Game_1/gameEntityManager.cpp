#include "gameEntityManager.h"
#include "global.h"
#include "runEnemy_1.h"
#include "enemy.h"
#include "runEnemy_1.h"
#include "runEnemy_2.h"
#include "runEnemy_3.h"
#include "runEnemy_4.h"
#include "math_manager.h"

#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

GameEntityManager::GameEntityManager()
{
	timeMax = 100;
	scoreTime = 0;
	time = 0;
	enemySpeed = 16;
	enemyCount = 3;
}

void GameEntityManager::ClearAll()
{
	isRunStage = false;
	isDirectionStage = false;

	if(runPlayer!=nullptr)
		runPlayer->setScore(0);
	scoreTime = 0;
	time = 0;
	enemySpeed = 16;
	timeMax = 100;
	enemyCount = 3;
	
	if (enemies.size() > 0) {
		enemies.clear();
	}
}

void GameEntityManager::AddEnemy(int type,int x)
{
	
	if (type == 0) {
		Enemy* enemy = new RunEnemy_1();
		x = 1280;
		enemy->setPosX(x - type);
		enemy->setSpeed(enemySpeed);
		enemies.push_back(enemy);
	}
	else if (type == 1) {
		Enemy* enemy = new RunEnemy_2();
		x = 1280;
		enemy->setPosX(x - type);
		enemy->setSpeed(enemySpeed);
		enemies.push_back(enemy);
	}
	else if (type == 2) {
		Enemy* enemy = new RunEnemy_3();
		x = 1280;
		enemy->setPosX(x - type);
		enemy->setSpeed(enemySpeed);
		enemies.push_back(enemy);
	}
	else if (type == 3) {
		Enemy* enemy = new RunEnemy_4();
		x = 1280;
		enemy->setPosX(x - type);
		enemy->setPosY(BOTTOM_Y - CAT_HEIGHT/2-RUN_ENEMY4_HEIGHT-5);
		enemy->setSpeed(enemySpeed);
		enemies.push_back(enemy);
	}
	else if (type == 4) {
		Enemy* enemy = new RunEnemy_4();
		x = 1280;
		enemy->setPosX(x - type);
		enemy->setPosY(BOTTOM_Y - CAT_HEIGHT - RUN_ENEMY4_HEIGHT - 5);
		enemy->setSpeed(enemySpeed);
		enemies.push_back(enemy);

	}
	else if (type == 5) {
		Enemy* enemy = new RunEnemy_4();
		x = 1280;
		enemy->setPosX(x - type);
		enemy->setPosY(BOTTOM_Y  - RUN_ENEMY4_HEIGHT - 5);
		enemy->setSpeed(enemySpeed);
		enemies.push_back(enemy);
	}
	else if (type == 6) {
		Enemy* enemy = new RunEnemy_4();
		x = 1280;
		enemy->setPosX(x - type);
		enemy->setPosY(BOTTOM_Y - CAT_HEIGHT / 2 - RUN_ENEMY4_HEIGHT - 5);
		enemy->setSpeed(enemySpeed);
		enemies.push_back(enemy);

		enemy = new RunEnemy_4();
		x = 1280;
		enemy->setPosX(x - type);
		enemy->setPosY(BOTTOM_Y - CAT_HEIGHT - RUN_ENEMY4_HEIGHT - 30);
		enemy->setSpeed(enemySpeed);
		enemies.push_back(enemy);
	}
	
	
}


void GameEntityManager::Update()
{	
	if(isRunStage)
		runStageUpdate();

	if (isDirectionStage)
		directionUpdate();

}

void GameEntityManager::Render()
{
	if(isRunStage)
		runStageRender();

	if (isDirectionStage)
		directionRender();
}

void GameEntityManager::runStageUpdate()
{
	//player가 죽지 않았을 때만
	if (!runPlayer->getIsDead())
	{
		time += 1;
		scoreTime += 1;
		if (runPlayer->getScore() > 400)
			enemyCount = 7;

		if (scoreTime > 5) {
			runPlayer->isHit = false;
			runPlayer->AddScore();
			scoreTime = 0;

			//스피드업
			if (runPlayer->getScore() % 200 == 0)
			{
				enemySpeed += 2;
				if (enemySpeed >= 23) {
					enemySpeed = 23;
				}
			}
		}

		//난이도가 올라갈 때 약간의 틈
		if (runPlayer->getScore() % 200 != 0)
		{
			//시간이 지날때 마다 enemy추가 
			if (time >= timeMax - enemySpeed)
			{
				int type = rand() % enemyCount;
				AddEnemy(type, 0);
				time = 0;
			}
		}
		else {
			time = 0;
		}

	}


	//플레이어와 enemy충돌처리
	for (auto iter = enemies.begin(); iter != enemies.end();)
	{
		if (isBoxCollided(runPlayer->getPlayerX(), runPlayer->getPlayerY(), runPlayer->getWidth(), runPlayer->getHeight(),
			(*iter)->getPosX(), (*iter)->getPosY(), (*iter)->getWidth(), (*iter)->getHeight()))
		{
			//runPlayer->isHITED();
			runPlayer->setIsDead(true);
		}
		iter++;
	}



	//enemy
	for (auto iter = enemies.begin(); iter != enemies.end();)
	{

		if ((*iter)->getPosX() < -300)
		{
			iter = enemies.erase(iter);
		}
		else
		{
			(*iter)->Update();
			iter++;
		}
	}
}

void GameEntityManager::runStageRender()
{
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->Render();
	}
}

void GameEntityManager::directionUpdate()
{

}

void GameEntityManager::directionRender()
{

}