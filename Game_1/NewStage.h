#pragma once
#include "Stage.h"
#include "Player.h"
#include "global.h"
#include <vector>
#include <d3dx9.h>

using namespace std;

class NewStage :public Stage
{
public:
	NewStage();
	void Render()override;
	void Update() override;

	void CatRender();
	
	void OnOff();
	
	int classType;
	int cat1_state;
	int cat2_state;
	int cat3_state;

	bool isCheck;
	bool isOn_1;
	bool isOn_2;
	bool isOn_3;

	int start_state;
	
	int id;

	vector<char> cname;
	ID3DXFont* font = nullptr;
	Player player;

};