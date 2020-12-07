#pragma once
#include "Stage.h"
#include "runStage_ui.h"
#include "gameOver.h"
class MiniGameDirectionStage:public Stage
{
public:

	MiniGameDirectionStage();
	void Render()override;

	void Update() override;


	RunStage_Ui runStage_ui;
	GameOver gameOver;
};