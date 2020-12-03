#pragma once
#include "Stage.h"
#include "runBackground.h"
#include "runPlayer.h"

class MiniGameRunStage:public Stage
{
public:
	MiniGameRunStage();
	void Render();
	void Update();
	
	RunBackGround runBackground;
	RunPlayer runPlayer;
	
};