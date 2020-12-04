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
	
	float jumpHeight = 0;
	float jumpTime = 0.0f;
	float jumpPower;


	float a = 0;
	float b = 0;

	RunPlayer();
	void Update();
	void Render();
	void Jump();
};