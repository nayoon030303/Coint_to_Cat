#pragma once
#include "runEnemy_1.h"
#include "global.h"

RunEnemy_1::RunEnemy_1()
{
	posX = WINDOW_WIDTH;
	posY = BOTTON_Y;
	isDead = false;
	radious =0;
	classType =0;
}

void RunEnemy_1::Render()
{
	TextureElement* element = textureManager.GetTexture(RUN_ENEMY1);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = RUN_ENEMY1_WIDTH;
	rc.bottom = RUN_ENEMY2_HEIGHT;

	D3DXVECTOR3 pos(posX, posY, 0);
	D3DXVECTOR3 cen(RUN_ENEMY1_WIDTH / 2, RUN_ENEMY2_HEIGHT / 2, 0);

	element->g_pSprite->Draw(element->g_Texture, &rc, &cen, &pos, D3DCOLOR_XRGB(255, 255, 255));
	element->g_pSprite->End();
}

void RunEnemy_1::Update()
{
	posX -= 10;
}

void RunEnemy_1::setPosX(float x) { posX = x; }
float RunEnemy_1::GetPosX() { return posX; }
void RunEnemy_1::setPosY(float y) { posY = y; }
float RunEnemy_1::GetPosY() { return posY; }
void RunEnemy_1::setAlive(bool dead) { isDead = dead; }
bool RunEnemy_1::getAlive() { return isDead; }
void RunEnemy_1::setRadious(float radious) { radious = radious; }
bool RunEnemy_1::getRadious() { return radious; }
void RunEnemy_1::setCalssType(int type) {classType = type;};
bool RunEnemy_1::getClassType() { return classType; }