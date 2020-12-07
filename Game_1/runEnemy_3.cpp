#pragma once
#include "runEnemy_3.h"
#include "global.h"

RunEnemy_3::RunEnemy_3()
{
	posX = WINDOW_WIDTH;
	posY = BOTTOM_Y - RUN_ENEMY3_HEIGHT;
	isDead = false;
	radious = 0;
	classType = 0;
	speed = 15;

	width = RUN_ENEMY3_WIDTH;
	height = RUN_ENEMY3_HEIGHT;
}

void RunEnemy_3::Render()
{
	TextureElement* element = textureManager.GetTexture(RUN_ENEMY3);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = RUN_ENEMY3_WIDTH;
	rc.bottom = RUN_ENEMY3_HEIGHT;

	D3DXVECTOR3 pos(posX, posY, 0);
	//D3DXVECTOR3 cen(RUN_ENEMY3_WIDTH / 2, RUN_ENEMY3_HEIGHT / 2, 0);

	element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
	element->g_pSprite->End();
}

void RunEnemy_3::Update()
{
	if (!gameEntityManager.runPlayer->getIsDead())
	{
		posX -= speed;
	}
}

void RunEnemy_3::setPosX(float x) { posX = x; }
float RunEnemy_3::getPosX() { return posX; }
void RunEnemy_3::setPosY(float y) { posY = y; }
float RunEnemy_3::getPosY() { return posY; }
void RunEnemy_3::setAlive(bool dead) { isDead = dead; }
bool RunEnemy_3::getAlive() { return isDead; }
void RunEnemy_3::setRadious(float radious) { radious = radious; }
bool RunEnemy_3::getRadious() { return radious; }
void RunEnemy_3::setCalssType(int type) { classType = type; };
bool RunEnemy_3::getClassType() { return classType; }
void RunEnemy_3::setWidth(int width) { width = width; };
int RunEnemy_3::getWidth() { return width; }
void RunEnemy_3::setHeight(int h) { height = h; };
int RunEnemy_3::getHeight() { return height; }
void RunEnemy_3::setSpeed(int sp) { speed = sp; }
int RunEnemy_3::getSpeed() { return speed; }