#include "runBackground.h"
#include "global.h"

RunBackGround::RunBackGround()
{
	
	screenX = 0;
}

void RunBackGround::Render()
{
	TextureElement* element = textureManager.GetTexture(MINIGAME_RUN_STAGE);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = WINDOW_WIDTH;
	rc.bottom = WINDOW_HEIGHT;

	int sx =(int(screenX) % WINDOW_WIDTH);

	D3DXVECTOR3 pos(sx, 0, 0);

	element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
	element->g_pSprite->End();


	element = textureManager.GetTexture(MINIGAME_RUN_STAGE);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = WINDOW_WIDTH;
	rc.bottom = WINDOW_HEIGHT;

	pos = D3DXVECTOR3(sx +WINDOW_WIDTH, 0, 0);

	element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
	element->g_pSprite->End();

	
}

void RunBackGround::Update()
{
	screenX -= 10.0f;
}