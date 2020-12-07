#include "global.h"
#include "MainStage.h"
#include <tchar.h>

#define GAME_X 290
#define GAME_XR 515
#define GAME_Y 610
#define GAME_YR 715


MainStage::MainStage()
{
    classType = MAIN_STAGE;

    //폰트1 생성
    HDC hDC = GetDC(NULL);
    int nLogPixelsY = GetDeviceCaps(hDC, LOGPIXELSY);
    ReleaseDC(NULL, hDC);
    int fontSize = 20;
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

void MainStage::Render()
{
    RECT srcRect;
    WCHAR text[256];
    WCHAR name[256] = { 0, };
     
    //배경
    TextureElement* element = textureManager.GetTexture(MAINSTAGE);
    element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = WINDOW_WIDTH;
    srcRect.bottom = WINDOW_HEIGHT;
    element->g_pSprite->Draw(element->g_Texture, &srcRect, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
    element->g_pSprite->End();

    //고양이
    element = textureManager.GetTexture(player->GetKind()*10);
    element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = CAT_WIDTH;
    srcRect.bottom = CAT_HEIGHT;
    D3DXVECTOR3 pos(800, 760,0);

    element->g_pSprite->Draw(element->g_Texture, &srcRect, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
    element->g_pSprite->End();

    //name
    srcRect.left = 0;
    srcRect.top = 0;
    MultiByteToWideChar(CP_ACP, 0, player->GetName(), strlen(player->GetName()), name, 256);
    _stprintf_s<256>(text, _T("이름:%s"), name);
    font1->DrawText(NULL, text, -1, &srcRect, DT_NOCLIP,
        D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

    //day
    srcRect.left = 200;
    srcRect.top = 0;
    text[256];
    _stprintf_s<256>(text, _T("day: %d"), player->GetDay());
    font1->DrawText(NULL, text, -1, &srcRect, DT_NOCLIP,
        D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

    //money
    srcRect.left = 400;
    srcRect.top = 0;
    text[256];
    _stprintf_s<256>(text, _T("coin: %d"), player->GetMoney());
    font1->DrawText(NULL, text, -1, &srcRect, DT_NOCLIP,
        D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

    //hp
    srcRect.left = 600;
    srcRect.top = 0;
    text[256];
    _stprintf_s<256>(text, _T("hp:%d"), player->GetHp());
    font1->DrawText(NULL, text, -1, &srcRect, DT_NOCLIP,
        D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

 
   
}

void MainStage::Update()
{
    //GAME
    if (pt.x > GAME_X && pt.x < GAME_XR && pt.y>GAME_Y && pt.y < GAME_YR)
    {
        if (inputManager.prevKey[VK_LBUTTON] == 1 && inputManager.key[VK_LBUTTON] == 0)
        {
            stageManager.MakeMiniGameChooseStage();
        }
    }

    

    


}