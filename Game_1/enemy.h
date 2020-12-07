#pragma once

class Enemy
{
public:

	float posX;
	float posY;
	bool isDead;
	float radious;
	int classType;
	float speed;
	int width;
	int height;

	virtual void setPosX(float x)  = 0;
	virtual float getPosX() = 0;
	
	virtual void setPosY(float y) = 0;;
	virtual float getPosY()  = 0;
	
	virtual void setAlive(bool dead) = 0;;
	virtual bool getAlive() = 0;
	
	virtual void setRadious(float radious) = 0;
	virtual bool getRadious() = 0;
	
	virtual void setCalssType(int type) = 0;
	virtual bool getClassType() = 0;

	virtual void setWidth(int width) = 0;
	virtual int getWidth() = 0;

	virtual void setHeight(int height) = 0;
	virtual int getHeight() = 0;

	virtual void setSpeed(int speed) = 0;
	virtual int getSpeed() = 0;

	virtual void  Update() = 0;
	virtual void Render() = 0;
};