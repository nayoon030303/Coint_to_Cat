#pragma once

class DirectionPlayer
{
public:
	float playerX;
	void setPlayerX(float x) { playerX = x; }
	float getPlayerX() { return playerX; }
	float playerY;
	void setPlayerY(float y) { playerY = y; }
	float getPlayerY() { return playerY; }
	
	void setScore(int sc) { score = sc; }
	int getScore() { return score; }
	void setIsDead(bool dead) { isDead = dead; }
	bool getIsDead() { return isDead; }
	void setWidth(int w) { width = w; }
	int getWidth() { return width; }
	void setHeight(int h) { height = h; }
	int getHeight() { return height; }
	

	int width;
	int height;
	int score = 0;
	bool isDead;

	DirectionPlayer();
	void Update();
	void Render();
	void AddScore();
};