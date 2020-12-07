#pragma once
#include "runEnemy_2.h"
#include "global.h"

RunEnemy_2::RunEnemy_2()
{
	posX = WINDOW_WIDTH;
	posY = BOTTOM_Y - RUN_ENEMY2_HEIGHT;
	isDead = false;
	radious = 0;
	classType = 0;
	speed = 15;

	width = RUN_ENEMY2_WIDTH;
	height = RUN_ENEMY2_HEIGHT;
}

void RunEnemy_2::Render()
{
	TextureElement* element = textureManager.GetTexture(RUN_ENEMY2);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = RUN_ENEMY2_WIDTH;
	rc.bottom = RUN_ENEMY2_HEIGHT;

	D3DXVECTOR3 pos(posX, posY, 0);
	//D3DXVECTOR3 cen(RUN_ENEMY2_WIDTH / 2, RUN_ENEMY2_HEIGHT / 2, 0);

	element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
	element->g_pSprite->End();
}

void RunEnemy_2::Update()
{
	if (!gameEntityManager.runPlayer->getIsDead())
	{
		posX -= speed;
	}
}

