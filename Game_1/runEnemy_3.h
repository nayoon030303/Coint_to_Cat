#pragma once
#include "enemy.h"
class RunEnemy_3 : public Enemy
{
public:
	RunEnemy_3();
	void Update()override;
	void Render()override;

	void setPosX(float x)override;
	float getPosX()override;

	void setPosY(float y)override;
	float getPosY()override;

	void setAlive(bool dead)override;
	bool getAlive()override;

	void setRadious(float radious)override;
	bool getRadious()override;

	void setCalssType(int type)override;
	bool getClassType()override;

	void setWidth(int width) override;
	int getWidth() override;

	void setSpeed(int speed)override;
	int getSpeed() override;

	void setHeight(int height) override;
	int getHeight() override;
};