#pragma once
#include "Stage.h"
#include "musicBackground.h"
#include "gameOver.h"
#include "musicPlayer.h"
#include "musicStage_ui.h"

class MiniGameMusicStage:public Stage
{
public:

	MiniGameMusicStage();
	void Render()override;
	void Update() override;

	MusicBackground musicBackground;
	MusicPlayer musicPlayer;
	MusicStage_ui musicStage_ui;
	GameOver gameOver;

	
};