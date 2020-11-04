#pragma once
#include "Stage.h"

class MainStage:public Stage
{
public:
	MainStage();
	void Render();
	void Update();

	ID3DXFont* font1;
	ID3DXFont* font2;

};