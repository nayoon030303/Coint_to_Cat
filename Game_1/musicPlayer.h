#pragma once

class MusicPlayer
{
public:
	
	void setPlayerX(float x) { playerX = x; }
	float getPlayerX() { return playerX; }

	void setPlayerY(float y) { playerY = y; }
	float getPlayerY() { return playerY; }
	void setScore(int sc) { score = sc; }
	int getScore() { return score; }
	void setWidth(int w) { width = w; }
	int getWidth() { return width; }
	void setHeight(int h) { height = h; }
	int getHeight() { return height; }
	void setTIme(int t) { time = t; }
	int getTime() { return time; }
	void setIsFinish(bool f) { isFinish = f; }
	bool getIsFinish() { return isFinish; }
	void setHp(int h) { hp = h; }
	int getHp() { return hp; }
	bool getIsGameOver() { return isGameOver; }
	void setIsGameOver(int over) { isGameOver = over; }
	void MinusHp();
	void AddScore();

	MusicPlayer();
	void Render();
	void Update();

	float playerY;
	float playerX;
	int time = 0;
	int score = 0;
	bool isFinish;
	bool isGameOver;
	
	int hp;
	int width;
	int height;
};