#include "MiniGameMusicStage.h"
#include "global.h"

MiniGameMusicStage::MiniGameMusicStage()
{
	gameEntityManager.musicPlayer = &musicPlayer;
	classType = MINI_GAME_MUSIC_STAGE;
	
}

void MiniGameMusicStage::Render()
{
	musicBackground.Render();
	gameEntityManager.Render();
	musicPlayer.Render();
	musicStage_ui.Render();
	if (musicPlayer.isGameOver)
	{
		gameOver.Render();
	}
	//directions.Render();
}

void MiniGameMusicStage::Update()
{
	musicBackground.Update();
	gameEntityManager.Update();
	musicPlayer.Update();
	musicStage_ui.Update();
	if (musicPlayer.isGameOver)
	{
		gameOver.Update();
	}
	//directions.Update();
}