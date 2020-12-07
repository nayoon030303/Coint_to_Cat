#include "musicBackground.h"
#include "global.h"

MusicBackground::MusicBackground()
{

}

void MusicBackground::Render()
{
	TextureElement* element = textureManager.GetTexture(MINIGAME_MUSIC_STAGE);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = WINDOW_WIDTH;
	rc.bottom = WINDOW_HEIGHT;


	element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	element->g_pSprite->End();


}

void MusicBackground::Update()
{
	

}