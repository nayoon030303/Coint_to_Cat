#pragma once
#include "enemy.h"
class RunEnemy_3 : public Enemy
{
public:
	RunEnemy_3();
	void Update()override;
	void Render()override;

};