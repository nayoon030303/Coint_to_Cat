#pragma once
#include "Stage.h"
#include <d3dx9.h>

class LoadStage:public Stage
{
public:
	
	LoadStage();
	void Render()override;
	void Update() override;

	ID3DXFont* font1;
	

	int max;
};