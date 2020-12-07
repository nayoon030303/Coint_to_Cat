#include "runStage_ui.h"
#include "global.h"
#include <tchar.h>

RunStage_Ui::RunStage_Ui()
{
   
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


   
}

void RunStage_Ui::Render()
{

    //점수
    RECT rc;
    rc.left = 100;
    rc.top = 100;
    WCHAR text[256];
    int score = gameEntityManager.runPlayer->getScore();
    _stprintf_s<256>(text, _T("score: %d"), score);
    font1->DrawText(NULL, text,-1,&rc,DT_NOCLIP,
        D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));


  
    //디버깅
    //speed
  /*  rc.left = 300;
    rc.top = 200;
    text[256];
    int speed = gameEntityManager.enemySpeed;
    _stprintf_s<256>(text, _T("score: %d"), speed);
    font1->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
        D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));*/
}

void RunStage_Ui::Update()
{

}