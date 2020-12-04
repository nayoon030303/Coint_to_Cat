#pragma once
#include "enemy.h"
class RunEnemy_1 : public Enemy
{
public:
	RunEnemy_1();
	void Update()override;
	void Render()override;

	void setPosX(float x)override;
	float GetPosX()override;

	void setPosY(float y)override;
	float GetPosY()override;

	void setAlive(bool dead)override;
	bool getAlive()override;

	void setRadious(float radious)override;
	bool getRadious()override;

	void setCalssType(int type)override;
	bool getClassType()override;

	float posX;
	float posY;
	bool isDead;
	float radious;
	int classType;

};