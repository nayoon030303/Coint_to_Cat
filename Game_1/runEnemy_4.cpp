#pragma once
#include "runEnemy_4.h"
#include "global.h"

RunEnemy_4::RunEnemy_4()
{
	//posX = WINDOW_WIDTH;
	posY = BOTTOM_Y - RUN_ENEMY1_HEIGHT;
	isDead = false;
	radious = 0;
	classType = 0;
	//speed = 30;

	width = RUN_ENEMY4_WIDTH;
	height = RUN_ENEMY4_HEIGHT;
}

void RunEnemy_4::Render()
{
	TextureElement* element = textureManager.GetTexture(RUN_ENEMY4);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = RUN_ENEMY4_WIDTH;
	rc.bottom = RUN_ENEMY4_HEIGHT;

	D3DXVECTOR3 pos(posX, posY, 0);
	//D3DXVECTOR3 cen(RUN_ENEMY1_WIDTH / 2, RUN_ENEMY1_HEIGHT / 2, 0);

	element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
	element->g_pSprite->End();
}

void RunEnemy_4::Update()
{
	if (!gameEntityManager.runPlayer->getIsDead())
	{
		posX -= speed;
	}

}

void RunEnemy_4::setPosX(float x) { posX = x; }
float RunEnemy_4::getPosX() { return posX; }
void RunEnemy_4::setPosY(float y) { posY = y; }
float RunEnemy_4::getPosY() { return posY; }
void RunEnemy_4::setAlive(bool dead) { isDead = dead; }
bool RunEnemy_4::getAlive() { return isDead; }
void RunEnemy_4::setRadious(float r) { radious = r; }
bool RunEnemy_4::getRadious() { return radious; }
void RunEnemy_4::setCalssType(int type) { classType = type; };
bool RunEnemy_4::getClassType() { return classType; }
void RunEnemy_4::setWidth(int w) { width = w; };
int RunEnemy_4::getWidth() { return width; }
void RunEnemy_4::setHeight(int h) { height = h; };
int RunEnemy_4::getHeight() { return height; }
void RunEnemy_4::setSpeed(int sp) { speed = sp; }
int RunEnemy_4::getSpeed() { return speed; }