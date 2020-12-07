#pragma once
#include <d3dx9.h>

class MusicStage_ui
{
public:
	MusicStage_ui();
	void Render();
	void Update();

	ID3DXFont* font1;
	ID3DXFont* font2;
};