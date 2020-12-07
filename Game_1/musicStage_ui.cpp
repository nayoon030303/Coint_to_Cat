#include "musicStage_ui.h"
#include "global.h"
#include <tchar.h>

MusicStage_ui::MusicStage_ui()
{
    //폰트1 생성
    HDC hDC = GetDC(NULL);
    int nLogPixelsY = GetDeviceCaps(hDC, LOGPIXELSY);
    ReleaseDC(NULL, hDC);
    int fontSize = 50;
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

    //폰트1 생성
    hDC = GetDC(NULL);
    nLogPixelsY = GetDeviceCaps(hDC, LOGPIXELSY);
    ReleaseDC(NULL, hDC);
    fontSize = 25;
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

void MusicStage_ui::Render()
{
   
 
    if (gameEntityManager.isGood)
    {
        RECT rc;
        rc.left = 300;
        rc.top = 750;
        WCHAR text[256];
        _stprintf_s<256>(text, _T("Good"));
        font1->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
            D3DXCOLOR(255.0f, 242.0f, 0.0f, 1.0f));
    }
    else if (gameEntityManager.isMiss)
    {
        RECT rc;
        rc.left = 300;
        rc.top = 750;
        WCHAR text[256];
        _stprintf_s<256>(text, _T("Miss"));
        font1->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
            D3DXCOLOR(255.0f, 0.0f, 0.0f, 1.0f));
    }
    //hp
    TextureElement* element;
    for (int i = 0; i < gameEntityManager.musicPlayer->getHp(); i++)
    {
        element = textureManager.GetTexture(HP);
        element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

        RECT rc;
        rc.left = 0;
        rc.top = 0;
        rc.right = 70;
        rc.bottom = 70;

        D3DXVECTOR3 pos(955+i*80, 35, 0);

        element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
        element->g_pSprite->End();
    }
   
    //점수
    RECT rc;
    rc.left = 955;
    rc.top = 135;
    WCHAR text[256];
    _stprintf_s<256>(text, _T("score: %d"),gameEntityManager.musicPlayer->getScore());
    font2->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
        D3DXCOLOR(255.0f, 255.0f, 255.0f, 1.0f));
  
}

void MusicStage_ui::Update()
{

}