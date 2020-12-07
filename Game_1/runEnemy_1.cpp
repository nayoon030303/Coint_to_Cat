#pragma once
#include "runEnemy_1.h"
#include "global.h"

RunEnemy_1::RunEnemy_1()
{
	//posX = WINDOW_WIDTH;
	posY = BOTTOM_Y - RUN_ENEMY1_HEIGHT;
	isDead = false;
	radious = 0;
	classType = 0;
	//speed = 30;

	width = RUN_ENEMY1_WIDTH;
	height = RUN_ENEMY1_HEIGHT;
}

void RunEnemy_1::Render()
{
	TextureElement* element = textureManager.GetTexture(RUN_ENEMY1);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = RUN_ENEMY1_WIDTH;
	rc.bottom = RUN_ENEMY1_HEIGHT;

	D3DXVECTOR3 pos(posX, posY, 0);
	//D3DXVECTOR3 cen(RUN_ENEMY1_WIDTH / 2, RUN_ENEMY1_HEIGHT / 2, 0);

	element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
	element->g_pSprite->End();
}

void RunEnemy_1::Update()
{
	if (!gameEntityManager.runPlayer->getIsDead())
	{
		posX -= speed;
	}
	
}

void RunEnemy_1::setPosX(float x) { posX = x; }
float RunEnemy_1::getPosX() { return posX; }
void RunEnemy_1::setPosY(float y) { posY = y; }
float RunEnemy_1::getPosY() { return posY; }
void RunEnemy_1::setAlive(bool dead) { isDead = dead; }
bool RunEnemy_1::getAlive() { return isDead; }
void RunEnemy_1::setRadious(float r) { radious = r; }
bool RunEnemy_1::getRadious() { return radious; }
void RunEnemy_1::setCalssType(int type) {classType = type;};
bool RunEnemy_1::getClassType() { return classType; }
void RunEnemy_1::setWidth(int w) { width = w; };
int RunEnemy_1::getWidth() { return width; }
void RunEnemy_1::setHeight(int h) { height = h; };
int RunEnemy_1::getHeight() { return height; }
void RunEnemy_1::setSpeed(int sp) { speed = sp; }
int RunEnemy_1::getSpeed() { return speed; }