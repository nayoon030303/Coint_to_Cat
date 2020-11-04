#pragma once
#include "Stage.h"

class GameRunStage:public Stage
{
public:
	GameRunStage();
	void Render();
	void Update();
};