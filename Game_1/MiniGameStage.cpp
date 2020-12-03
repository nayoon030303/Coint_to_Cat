#include "MiniGameStage.h"	
#include "global.h"

MiniGameStage::MiniGameStage()
{

}

void MiniGameStage::Render()
{
	RECT rc;

	TextureElement* element = textureManager.GetTexture(MINIGAMESTAGE);
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
	if (pt.x > 200 && pt.x < 400 && pt.y > 200 && pt.y < 400)
	{
		if (inputManager.prevKey[VK_LBUTTON] == 1 && inputManager.key[VK_LBUTTON] == 0)
		{
			stageManager.MakeMiniGameRunStage();
		}
	}
}