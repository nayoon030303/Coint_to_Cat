#pragma once
#include "Stage.h"
#include "runBackground.h"
#include "runPlayer.h"
#include "runEnemy_1.h"
#include "runStage_ui.h"
#include "gameOver.h"

class MiniGameRunStage:public Stage
{
public:
	MiniGameRunStage();
	void Render()override;

	void Update() override;
	
	
	RunBackGround runBackground;
	RunPlayer runPlayer;
	RunEnemy_1 runEnemy1; 
	RunStage_Ui runStage_ui;
	GameOver gameOver;
};