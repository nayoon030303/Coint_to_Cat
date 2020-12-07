#include "MiniGameRunStage.h"	
#include "global.h"


MiniGameRunStage::MiniGameRunStage()
{
	gameEntityManager.runPlayer = &runPlayer;
	classType = MINI_GAME_RUN_STAGE;
}

void MiniGameRunStage::Render()
{
	runBackground.Render(); 
	runPlayer.Render();
	gameEntityManager.Render();
	runStage_ui.Render();
	if (runPlayer.isDead)
	{
		gameOver.Render();
	}
}

void MiniGameRunStage::Update()
{
	runBackground.Update();
	runPlayer.Update();

	gameEntityManager.Update();
	if (runPlayer.isDead)
	{
		gameOver.Update();
	}
}