#pragma once

class Enemy
{
public:

	void setPosX(float x) { posX = x; }
	float getPosX() { return posX; }
	
	void setPosY(float y) { posY = y; }
	float getPosY() { return posY; }
	
	void setAlive(bool dead) { isDead = dead; }
	bool getAlive() { return isDead; }
	
	void setRadious(float r) { radious = r; }
	bool getRadious() { return radious; }
	
	void setCalssType(int type) { classType = type; };
	bool getClassType() { return classType; }

	void setWidth(int w) { width = w; };
	int getWidth() { return width; }

	void setHeight(int h) { height = h; };
	int getHeight() { return height; }

	void setSpeed(int sp) { speed = sp; }
	int getSpeed() { return speed; }

	virtual void  Update() = 0;
	virtual void Render() = 0;

	float posX;
	float posY;
	bool isDead;
	float radious;
	int classType;
	float speed;
	int width;
	int height;

};