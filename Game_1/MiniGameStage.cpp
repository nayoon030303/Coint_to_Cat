#include "MiniGameStage.h"	
#include "global.h"

MiniGameStage::MiniGameStage()
{
	state = MINIGAMESTAGE;
	classType = MINI_GAME_CHOOSE;
}

void MiniGameStage::Render()
{
	RECT rc;

	TextureElement* element = textureManager.GetTexture(state);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;
	rc.top = 0;
	rc.right = WINDOW_WIDTH;
	rc.bottom = WINDOW_HEIGHT;
	element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	element->g_pSprite->End();
	
}

void MiniGameStage::Update()
{
	state = MINIGAMESTAGE;

	//´Þ¸®±â
	if (pt.x > 600 && pt.x < 650 && pt.y > 265 && pt.y < 300)
	{
		state = MINIGAMESTAGE_1;
		if (inputManager.prevKey[VK_LBUTTON] == 1 && inputManager.key[VK_LBUTTON] == 0)
		{
			stageManager.MakeMiniGameRunStage();
		}
	}

	//À½¾Ç
	if (pt.x > 980 && pt.x < 1030 && pt.y > 465 && pt.y < 515)
	{
		state = MINIGAMESTAGE_2;
		if (inputManager.prevKey[VK_LBUTTON] == 1 && inputManager.key[VK_LBUTTON] == 0)
		{
			stageManager.MakeMiniGameMusicStage();
		}
	}
}