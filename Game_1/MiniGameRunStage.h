#pragma once
#include "Stage.h"
#include "runBackground.h"
#include "runPlayer.h"
#include "runEnemy_1.h"

class MiniGameRunStage:public Stage
{
public:
	MiniGameRunStage();
	void Render();
	void Update();
	
	RunBackGround runBackground;
	RunPlayer runPlayer;
	RunEnemy_1 runEnemy1; 
};