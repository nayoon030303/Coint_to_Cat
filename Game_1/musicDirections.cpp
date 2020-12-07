#include "musicDirections.h"
#include "global.h"

MusicDirections::MusicDirections()
{
	width = 130;
	height = 130;
	posY = -150;
	posX = 15;
	type = 0;
}

void MusicDirections::Render()
{
	TextureElement* element = textureManager.GetTexture(DIRECTIONS);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT rc;
	rc.left = 0+150*type;
	rc.top = 0;
	rc.right = 150 + 150* type;
	rc.bottom = 150;

	D3DXVECTOR3 pos(posX, posY, 0);

	element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
	element->g_pSprite->End();
}

void MusicDirections::Update()
{
	posY+=10;
}