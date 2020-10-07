#include "LoadStage.h"
#include "global.h"
#include <tchar.h>

#define TEXT_X  WINDOW_WIDTH/2-275

#define LOAD_SQUARE_WIDTH 1100
#define LOAD_SQUARE_HEIGHT 155
#define LOAD_SQUARE_X (WINDOW_WIDTH-LOAD_SQUARE_WIDTH)/2
#define LOAD_SQUARE_Y 170


LoadStage::LoadStage()
{
    max = gameStat.GetMax();

   //��Ʈ1 ����
   HDC hDC = GetDC(NULL);
   int nLogPixelsY = GetDeviceCaps(hDC, LOGPIXELSY);
   ReleaseDC(NULL, hDC);
   int fontSize = 30;
   int nHeight = -fontSize * nLogPixelsY / 72;
   TCHAR g_strFont[LF_FACESIZE];
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
       &font1);


}

void LoadStage::Render()
{
    //���
	TextureElement* element = textureManager.GetTexture(LOADSTAGE);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
    RECT rc;
    rc.left = 0;
    rc.top = 0;
    rc.right = WINDOW_WIDTH;
    rc.bottom = WINDOW_HEIGHT;

    element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
    element->g_pSprite->End();


    //TEXT
    rc;
    rc.left = TEXT_X;
    rc.top = 50;
    WCHAR text[256];
     _stprintf_s<256>(text, _T("����� ������ Ŭ�����ּ���"));
     font1->DrawText(nullptr, text, -1, &rc, DT_NOCLIP,
          D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

     //ĳ���� ���� ĭ
     element = textureManager.GetTexture(LOAD_SQUARE);
     element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
     rc.left = 0;
     rc.top = 0;
     rc.bottom = LOAD_SQUARE_HEIGHT;
     rc.right = LOAD_SQUARE_WIDTH;
     D3DXVECTOR3 pos;
     for (int i = 1; i <=4; i++)
     {
         pos = D3DXVECTOR3(LOAD_SQUARE_X, LOAD_SQUARE_Y * i, 0);
         element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
     }
     element->g_pSprite->End();

     //������ TEXT
     for (int i = 0; i < max; i++)
     {
         rc;
         rc.left = LOAD_SQUARE_X+40;
         rc.top = LOAD_SQUARE_Y * (i + 1) + 20;
         WCHAR text[256];
         WCHAR abc[256] = { 0, };
         //char str[256] = "�ʱ�ȭ�� �ʼ�";
         MultiByteToWideChar(CP_ACP, 0, playerInfos[i].GetName(), strlen(playerInfos[i].GetName()), abc, 256);

         _stprintf_s<256>(text, _T("�̸�:%s"), abc);
         font1->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
             D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f)); 

     }
     for (int i = 0; i < MAX_INFO - max; i++)
     {

     }
}

void LoadStage::Update()
{
     


}