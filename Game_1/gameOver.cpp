#include "gameOver.h"
#include "global.h"
#include <tchar.h>

GameOver::GameOver()
{



	HDC hDC = GetDC(NULL);
	int nLogPixelsY = GetDeviceCaps(hDC, LOGPIXELSY);
	ReleaseDC(NULL, hDC);

	int fontSize = 30;
	TCHAR g_strFont[256];
	wcscpy_s(g_strFont, 32, L"둥근모꼴");

	int nHeight = -fontSize * nLogPixelsY / 72;
	D3DXCreateFont(g_pd3dDevice,
		nHeight,
		0,
		FW_BOLD,
		1,
		FALSE,
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		g_strFont,
		&font1);

	hDC = GetDC(NULL);
	nLogPixelsY = GetDeviceCaps(hDC, LOGPIXELSY);
	ReleaseDC(NULL, hDC);
	fontSize = 60;
	nHeight = -fontSize * nLogPixelsY / 72;
	g_strFont[LF_FACESIZE];
	wcscpy_s(g_strFont, 32, L"Arial");
	D3DXCreateFont(g_pd3dDevice,            // D3D device
		nHeight,               // Height
		0,                     // Width
		FW_BOLD,               // Weight
		1,                     // MipLevels, 0 = autogen mipmaps
		FALSE,                 // Italic
		DEFAULT_CHARSET,       // CharSet
		OUT_DEFAULT_PRECIS,    // OutputPrecision
		DEFAULT_QUALITY,       // Quality
		DEFAULT_PITCH | FF_DONTCARE, // PitchAndFamily
		g_strFont,              // pFaceName
		&font2);
}

void GameOver::Render()
{
	//background
	TextureElement* element = textureManager.GetTexture(GAME_OVER);
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;
	rc.top = 0;
	rc.right = GAME_OVER_TEXTURE_WIDTH;
	rc.bottom = GAME_OVER_TEXTULRE_HEIGHT;
	pos = { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0 };
	cen = { GAME_OVER_TEXTURE_WIDTH / 2, GAME_OVER_TEXTULRE_HEIGHT / 2, 0 };
	element->g_pSprite->Draw(element->g_Texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->g_pSprite->End();
	
	//버튼
	element = textureManager.GetTexture(MAIN_BUTTON);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = MINIGAME_BUTTON_WIDTH;
	rc.bottom = MINIGAME_BUTTON_HEIGHT;

	pos = { MINIGAME_BUTTON_X, MINIGAME_BUTTON_Y, 0 };

	element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->g_pSprite->End();



	//점수
	rc;
	rc.left = 200;
	rc.top = 350;
	rc.right = 15;
	rc.bottom = 15;
	WCHAR text[256];
	_stprintf_s<256>(text, _T("점수"));
	font1->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

	rc.left = 500;
	rc.top = 350;
	rc.right = 15;
	rc.bottom = 15;
	score = gameEntityManager.runPlayer->getScore();
	_stprintf_s<256>(text, _T(":  %d"), score);
	font1->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.21f, 0.05f, 0.35f, 1.0f));



	//얻은 코인
	rc.left = 200;
	rc.top = 450;
	rc.right = 15;
	rc.bottom = 15;
	_stprintf_s<256>(text, _T("얻은 코인 "));
	font1->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	rc.left = 500;
	rc.top = 450;
	rc.right = 15;
	rc.bottom = 15;
	_stprintf_s<256>(text, _T(":  %d"), score*2);
	font1->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.21f, 0.05f, 0.35f, 1.0f));



	//총합
	rc.left = 200;
	rc.top = 650;
	rc.right = 15;
	rc.bottom = 15;
	_stprintf_s<256>(text, _T("총합 코인"));
	font1->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.21f, 0.05f, 0.35f, 1.0f));

	int money = player->GetMoney();

	rc.left = 500;
	rc.top = 650;
	rc.right = 15;
	rc.bottom = 15;
	_stprintf_s<256>(text, _T(":  %d"), money);
	font1->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.21f, 0.05f, 0.35f, 1.0f));

	rc.left = 700;
	rc.top = 650;
	rc.right = 15;
	rc.bottom = 15;
	_stprintf_s<256>(text, _T(" +  %d = %d "), score * 2, money+(score*2));
	font1->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.21f, 0.05f, 0.35f, 1.0f));
	
	
	
	
}

void GameOver::Update()
{
	
	if (pt.x > MINIGAME_BUTTON_X && pt.x<MINIGAME_BUTTON_X + MINIGAME_BUTTON_WIDTH && pt.y> MINIGAME_BUTTON_Y && pt.y < MINIGAME_BUTTON_Y + MINIGAME_BUTTON_WIDTH)
	{
		if (inputManager.prevKey[VK_LBUTTON] == 1 && inputManager.key[VK_LBUTTON] == 0)
		{
		
			player->SetMoney(player->GetMoney()+ score*2);
			stageManager.MakeMainStage();
		}
	}
}