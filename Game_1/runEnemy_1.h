#pragma once
#include "enemy.h"
class RunEnemy_1 : public Enemy
{
public:
	RunEnemy_1();
	void Update()override;
	void Render()override;
	
};