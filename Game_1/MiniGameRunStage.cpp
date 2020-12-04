#include "MiniGameRunStage.h"	
#include "global.h"




MiniGameRunStage::MiniGameRunStage()
{
	
}

void MiniGameRunStage::Render()
{
	runBackground.Render(); 
	runPlayer.Render();
	runEnemy1.Render();
	gameEntityManager.Render();
}

void MiniGameRunStage::Update()
{
	runBackground.Update();
	runPlayer.Update();
	runEnemy1.Update();

	gameEntityManager.Update();

}