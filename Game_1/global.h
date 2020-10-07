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



//������ ������
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 1024

//�̹��� �ѹ�//

//���(stage)
#define TITLE 100
#define NEWSTAGE 200
#define MAINSTAGE 300
#define LOADSTAGE 400
#define LOAD_SQUARE 500

//������Ʈ
#define CAT_1 1000
#define CAT_2 1100
#define CAT_3 1300

//��ư
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
extern vector<Player> playerInfos;
