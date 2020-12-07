#pragma once
class Stage
{
public:
	virtual void Render() = 0;
	virtual void Update() = 0;

	int classType;
};