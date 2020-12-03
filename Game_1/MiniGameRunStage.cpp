#include "MiniGameRunStage.h"	
#include "global.h"




MiniGameRunStage::MiniGameRunStage()
{
	
}

void MiniGameRunStage::Render()
{
	runBackground.Render(); 
	runPlayer.Render();
	
	
}

void MiniGameRunStage::Update()
{
	runBackground.Update();
	runPlayer.Update();

}