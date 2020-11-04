#include "LoadStage.h"
#include "global.h"
#include <tchar.h>

#define TEXT_X  WINDOW_WIDTH/2-275

#define LOAD_SQUARE_WIDTH 920
#define LOAD_SQUARE_HEIGHT 115
#define LOAD_SQUARE_X (WINDOW_WIDTH-LOAD_SQUARE_WIDTH)/2
#define LOAD_SQUARE_Y 270
#define MARGIN_Y 33


LoadStage::LoadStage()
{
    max = gameStat.GetMax();

   //폰트1 생성
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

   //폰트2 생성
   hDC = GetDC(NULL);
   nLogPixelsY = GetDeviceCaps(hDC, LOGPIXELSY);
   ReleaseDC(NULL, hDC);
   fontSize = 20;
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

void LoadStage::Render()
{
    RECT rc;
    WCHAR text[256];

    //배경
	TextureElement* element = textureManager.GetTexture(LOADSTAGE);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
    rc.left = 0;
    rc.top = 0;
    rc.right = WINDOW_WIDTH;
    rc.bottom = WINDOW_HEIGHT;
    element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
    element->g_pSprite->End();


    //TEXT
   /* rc;
    rc.left = TEXT_X;
    rc.top = 50;
     _stprintf_s<256>(text, _T("당신의 파일을 클릭해주세요"));
     font1->DrawText(nullptr, text, -1, &rc, DT_NOCLIP,
          D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));*/

     //캐릭터 선택 칸
     element = textureManager.GetTexture(LOAD_SQUARE);
     element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
     rc.left = 0;
     rc.top = 0;
     rc.bottom = LOAD_SQUARE_HEIGHT;
     rc.right = LOAD_SQUARE_WIDTH;
     D3DXVECTOR3 pos;
     for (int i = 0; i <4; i++)
     {
         pos = D3DXVECTOR3(LOAD_SQUARE_X, LOAD_SQUARE_Y + (LOAD_SQUARE_HEIGHT+20) *i, 0);
         element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
     }
     element->g_pSprite->End();

     //데이터 TEXT
     for (int i = 0; i < max; i++)
     {
         //id
         rc.left = LOAD_SQUARE_X + 20;
         rc.top = LOAD_SQUARE_Y + (LOAD_SQUARE_HEIGHT + 20) * i +MARGIN_Y;
         WCHAR text[256];
         int id = playerInfos[i].GetId();
         _stprintf_s<256>(text, _T("0%d"), id);
         font2->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
             D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

         //이름
         rc.left = LOAD_SQUARE_X+80;
         rc.top = LOAD_SQUARE_Y + (LOAD_SQUARE_HEIGHT + 20) * i + MARGIN_Y;
         text[256];
         WCHAR name[256] = { 0, };
         MultiByteToWideChar(CP_ACP, 0, playerInfos[i].GetName(), strlen(playerInfos[i].GetName()), name, 256);
         _stprintf_s<256>(text, _T("이름:%s"), name);
         font2->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
             D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f)); 

     }
     //데이터 x
     for (int i = 0; i < MAX_INFO - max; i++)
     {
        
         rc.left = LOAD_SQUARE_X + 20;
         int startY = LOAD_SQUARE_Y + (LOAD_SQUARE_HEIGHT + 20) * max + MARGIN_Y;
         rc.top = startY + (LOAD_SQUARE_HEIGHT + 20) * i;
         WCHAR text[256];
         WCHAR test[256] = { 0, };
         char noData[256] = "데이터가 없습니다";
         MultiByteToWideChar(CP_ACP, 0,noData, strlen(noData), test, 256);
         _stprintf_s<256>(text, _T("%s"), test);
         font2->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
             D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

     }
}

void LoadStage::Update()
{
     
    //선택한 데이터 불러오기
    for (int i = 0; i < max; i++)
    {
        if (pt.x > LOAD_SQUARE_X && pt.x<LOAD_SQUARE_X + LOAD_SQUARE_WIDTH
            && pt.y>(LOAD_SQUARE_Y + (LOAD_SQUARE_HEIGHT + 20) * i) && pt.y < LOAD_SQUARE_Y + (LOAD_SQUARE_HEIGHT + 20) * i + LOAD_SQUARE_HEIGHT)
        {
            if (inputManager.prevKey[VK_LBUTTON] == 1 && inputManager.key[VK_LBUTTON] == 0)
            {
                //player.id = 200;
                player.id = playerInfos[i].GetId();
                strcpy_s(player.name, playerInfos[i].GetName());
                player.catKind = playerInfos[i].GetKind();
                player.day = playerInfos[i].GetDay();
                player.money = playerInfos[i].GetMoney();
                player.hp = playerInfos[i].GetHp();
                player.coin1 = playerInfos[i].GetCoin1();
                player.coin2 = playerInfos[i].GetCoin2();
                player.coin3 = playerInfos[i].GetCoin3();
                player.coin4 = playerInfos[i].GetCoin4();
                player.time = playerInfos[i].GetTime();

                stageManager.MakeMainStage();
                return ; 

            }
        }
    }
    //new 페이지 
    for (int i = 0; i < MAX_INFO - max; i++)
    {
        if (pt.x > LOAD_SQUARE_X && pt.x < LOAD_SQUARE_X + LOAD_SQUARE_WIDTH
            && pt.y> LOAD_SQUARE_Y + (LOAD_SQUARE_HEIGHT + 20) * max + MARGIN_Y + (LOAD_SQUARE_HEIGHT + 20) * i 
            && pt.y<LOAD_SQUARE_Y + (LOAD_SQUARE_HEIGHT + 20) * max + MARGIN_Y + (LOAD_SQUARE_HEIGHT + 20) * i + LOAD_SQUARE_HEIGHT)
        {
            if (inputManager.prevKey[VK_LBUTTON] == 1 && inputManager.key[VK_LBUTTON] == 0)
            {
                stageManager.MakeNewStage();
                return;

            }
           
        }
    }

}