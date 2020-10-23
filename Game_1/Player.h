#pragma once
#include <string>
#include <string.h>
#include <string>

using namespace std;

class Player
{
public:
	Player();

	int id;
	char name[128];

	enum CatKind //고양이 종류(이미지)
	{
		c1 = 1,
		c2,
		c3
	};
	int catKind;
	int day;
	int hp;
	int money;
	int coin1, coin2, coin3, coin4;
	int time;

	//id
	void SetId(int id) { this->id = id; }
	int GetId() { return id; }

	//name
	void SetName(string name) { strcpy_s(this->name, name.c_str()); }
	char* GetName() { return name; }

	//kind
	void SetKind(int kind) { this->catKind = kind; }
	int GetKind() { return catKind; }

	//day
	void SetDay(int day) { this->day = day; }
	int GetDay() { return day; }


	//money
	void SetMoney(int money) { this->money = money; }
	int GetMoney() { return money; }


	//hp
	void SetHp(int hp) { this->hp = hp; }
	int GetHp() { return hp; }

	
	
	//coin1
	void SetCoin1(int kind) { this->coin1 = coin1; }
	int GetCoin1() { return coin1; }

	//coin2
	void SetCoin2(int kind) { this->coin2 = coin2; }
	int GetCoin2() { return coin2; }

	//coin3
	void SetCoin3(int kind) { this->coin3 = coin3; }
	int GetCoin3() { return coin3; }

	//coin4
	void SetCoin4(int kind) { this->coin4 = coin4; }
	int GetCoin4() { return coin4; }

	//time
	void SetTime(int kind) { this->time = time; }
	int GetTime() { return time; }


	void Render();
	void Update();
};