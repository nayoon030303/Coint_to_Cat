#pragma once
#include "Stage.h"
#include "gameOver.h"

class MiniGameRuckSissorsPaper : public Stage
{
public:

	MiniGameRuckSissorsPaper();
	void Render()override;
	void Update() override;

	GameOver gameOver;
};