#pragma once
#include "Stage.h"

class MiniGameStage :public Stage
{
public:
	MiniGameStage() ;
	void Render() override;
	void Update() override;
	int state;

};
