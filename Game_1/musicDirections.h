#pragma once

class MusicDirections
{
public:
	MusicDirections();
	void Render();
	void Update();

	void setPosx(float x) { posX = x; }
	float getPosx() { return posX; }
	void setPosY(float y) { posY = y; }
	float getPosY() { return posY; }
	void setWidth(int w) { width = w; }
	int getWidth() { return width; }
	void setHeight(int h) { height = h; }
	int getHeight() { return height; }
	void setType(int t) { type = t; }
	int getType() { return type; }
	void setIsCorrect(bool c) { isCorrect = c; }
	bool getIsCorrect() { return isCorrect; }

	float posX;
	float posY;
	float width;
	float height;

	int type;
	bool isCorrect = false;
	bool isFail = false;

};