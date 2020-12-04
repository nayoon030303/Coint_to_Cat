#pragma once

class Enemy
{
public:

	float posX;
	float posY;
	bool isDead;
	float radious;
	int classType;

	virtual void setPosX(float x)  = 0;
	virtual float GetPosX() = 0;
	
	virtual void setPosY(float y) = 0;;
	virtual float GetPosY()  = 0;
	
	virtual void setAlive(bool dead) = 0;;
	virtual bool getAlive() = 0;
	
	virtual void setRadious(float radious) = 0;
	virtual bool getRadious() = 0;
	
	virtual void setCalssType(int type) = 0;
	virtual bool getClassType() = 0;

	virtual void  Update() = 0;
	virtual void Render() = 0;
};