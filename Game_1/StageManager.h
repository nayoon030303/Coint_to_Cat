#pragma once
class Stage;

class StageManager
{
public:
	StageManager();

	void MakeTitleStage();
	void MakeNewStage();
	void MakeLoadStage();
	void MakeMainStage();
	void MakeMiniGameChooseStage();
	void MakeMiniGameRunStage();

	//±âº»
	void Render();
	void Update();



	//stage
	Stage* currentStage;
	Stage* prevStage;
};