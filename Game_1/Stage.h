#pragma once
#include "musicDirections.h"
#include "musicPlayer.h"

class Stage
{
public:
	virtual void Render() = 0;
	virtual void Update() = 0;

	MusicDirections directions;
	MusicPlayer musicPlayer; 
	int classType;
};