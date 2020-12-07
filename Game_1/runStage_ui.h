#pragma once
#include <d3dx9.h>

class RunStage_Ui
{
public:
	RunStage_Ui();
	void Render();
	void Update();
	
	ID3DXFont* font1;
	ID3DXFont* font2;
};