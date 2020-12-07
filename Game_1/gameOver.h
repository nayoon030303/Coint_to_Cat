#pragma once

#include "Stage.h"
#include <d3dx9.h>

class GameOver:public Stage
{
public:
	GameOver();
	void Render() override;
	void Update() override;
	ID3DXFont* font1;
	ID3DXFont* font2;
	int classType;
	int score;
	int getCoin;

};