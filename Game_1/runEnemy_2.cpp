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

void RunEnemy_2::setPosX(float x) { posX = x; }
float RunEnemy_2::getPosX() { return posX; }
void RunEnemy_2::setPosY(float y) { posY = y; }
float RunEnemy_2::getPosY() { return posY; }
void RunEnemy_2::setAlive(bool dead) { isDead = dead; }
bool RunEnemy_2::getAlive() { return isDead; }
void RunEnemy_2::setRadious(float radious) { radious = radious; }
bool RunEnemy_2::getRadious() { return radious; }
void RunEnemy_2::setCalssType(int type) { classType = type; };
bool RunEnemy_2::getClassType() { return classType; }
void RunEnemy_2::setWidth(int width) { width = width; };
int RunEnemy_2::getWidth() { return width; }
void RunEnemy_2::setHeight(int h) { height = h; };
int RunEnemy_2::getHeight() { return height; }
void RunEnemy_2::setSpeed(int sp) { speed = sp; }
int RunEnemy_2::getSpeed() { return speed; }