#pragma once

#include <Windows.h>
#include <mmsystem.h>
#include <d3dx9.h>
#pragma warning( disable : 4996 ) // disable deprecated warning 
#include <strsafe.h>
#pragma warning( default : 4996 )

#include "TextureManager.h"
#include "InputManager.h"
#include "StageManager.h"
#include "Player.h"
#include "GameStat.h"



//윈도우 사이즈
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 1024

//이미지 넘버//

//배경(stage)
#define TITLE 100
#define NEWSTAGE 200
#define MAINSTAGE 300
#define LOADSTAGE 400
#define LOAD_SQUARE 500
#define MINIGAMESTAGE 600

//오브젝트
#define CATN_1 1
#define CATN_2 2
#define CATN_3 3

#define CATM_1 10
#define CATM_2 20
#define CATM_3 30


//버튼
#define START 2100
#define START_BORDER 2200


#define MAX_HP 5
#define MAX_INFO 4



extern HWND hWnd;
extern LPDIRECT3D9         g_pD3D ;
extern LPDIRECT3DDEVICE9   g_pd3dDevice ;


extern POINT pt;

extern TextureManager textureManager;
extern InputManager inputManager;
extern StageManager stageManager;
extern GameStat gameStat;
extern vector<Player> playerInfos;	//데이터 저장
extern Player player;	//플레이어
