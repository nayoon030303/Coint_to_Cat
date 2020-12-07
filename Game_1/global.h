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
#include "gameEntityManager.h"



//������ ������
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 1024

//Ŭ���� Ÿ��
#define MINI_GAME_CHOOSE 2000
#define TITLE_STAGE 2001
#define NEW_STAGE 2002
#define MINI_GAME_RUN_STAGE 2003
#define MAIN_STAGE 2004
#define LOAD_STAGE 2005
#define MINI_GAME_DIRECTION_STAGE 2006


//�̹��� �ѹ�//

//���(stage)
#define TITLE 100
#define NEWSTAGE 200
#define MAINSTAGE 300
#define LOADSTAGE 400
#define LOAD_SQUARE 500
#define MINIGAMESTAGE 600
#define MINIGAME_RUN_STAGE 700
#define RESULT 800
#define GAME_OVER 900

//������Ʈ
#define CATN_1 1
#define CATN_2 2
#define CATN_3 3
#define CATM_1 10
#define CATM_2 20
#define CATM_3 30

#define RUN_ENEMY1 40
#define RUN_ENEMY2 50
#define RUN_ENEMY3 60
#define RUN_ENEMY4 70

//��ư
#define START 2100
#define START_BORDER 2200
#define MAIN_BUTTON 2300

#define MAX_HP 5
#define MAX_INFO 4

//�̹��� ũ��
#define CAT_WIDTH 150
#define CAT_HEIGHT 200
#define RUN_ENEMY1_WIDTH  130
#define RUN_ENEMY1_HEIGHT  160
#define RUN_ENEMY2_WIDTH  100
#define RUN_ENEMY2_HEIGHT  230
#define RUN_ENEMY3_WIDTH  250
#define RUN_ENEMY3_HEIGHT  150
#define RUN_ENEMY4_WIDTH  150
#define RUN_ENEMY4_HEIGHT  130
#define GAME_OVER_TEXTURE_WIDTH 1150
#define GAME_OVER_TEXTULRE_HEIGHT 800
#define MINIGAME_BUTTON_WIDTH 200
#define MINIGAME_BUTTON_HEIGHT 80
#define BOTTOM_Y  880

//��ġ
#define MINIGAME_BUTTON_X 980
#define MINIGAME_BUTTON_Y 780

extern HWND hWnd;
extern LPDIRECT3D9         g_pD3D ;
extern LPDIRECT3DDEVICE9   g_pd3dDevice ;

extern POINT pt;
extern GameEntityManager gameEntityManager;
extern TextureManager textureManager;
extern InputManager inputManager;
extern StageManager stageManager;
extern GameStat gameStat;
extern vector<Player> playerInfos;	//������ ����
extern Player* player;	//�÷��̾�

