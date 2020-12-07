#pragma once

class RunPlayer
{
public:
	float playerX;
	void setPlayerX(float x) { playerX = x; }
	float getPlayerX() { return playerX; }
	float playerY;
	void setPlayerY(float y) { playerY = y; }
	float getPlayerY() { return playerY; }
	bool isBottom;
	void setIsBottom(bool bottom) { isBottom = bottom; }
	bool getIsBottom() { return isBottom; }
	bool isJump;
	void setIsJump(float jum) { isJump = jum; }
	float getIsJump() { return isJump; }
	void setScore(int sc) { score = sc; }
	int getScore() { return score; }
	void setIsDead(bool dead) { isDead = dead; }
	bool getIsDead() { return isDead; }
	void setWidth(int w) { width = w; }
	int getWidth() { return width; }
	void setHeight(int h) { height = h; }
	int getHeight() { return height; }
	void setIsDown(bool d) { isDown = d; }
	bool getIsDown() { return isDown; }
	
	float jumpHeight = 0;
	float jumpTime = 0.0f;
	float jumpPower;
	int width;
	int height;
	bool isDead;
	int score = 0;
	bool isHit;
	bool isDown;

	RunPlayer();
	void Update();
	void Render();
	void Jump();
	void AddScore();
	void isHITED();
};