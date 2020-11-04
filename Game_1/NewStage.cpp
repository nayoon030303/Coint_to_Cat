#include "NewStage.h"
#include "TextureManager.h"
#include "global.h"
#include <string>
#include <tchar.h>

#define CAT_WIDTH 300
#define CAT_HEIGHT 300

#define CAT_POSY 130

#define CAT1_POSX 110
#define CAT2_POSX CAT1_POSX+80+CAT_WIDTH
#define CAT3_POSX CAT2_POSX+80+CAT_WIDTH

#define START_POSX 1040
#define START_POSY 880

#define START_WIDTH 225
#define START_HEIGHT 115

#define CAT_ON  1
#define CAT_OFF 0

#define c1 1
#define c2 2
#define c3 3




NewStage::NewStage()
{
    cat1_state = CAT_OFF;
    cat2_state = CAT_OFF;
    cat3_state = CAT_OFF;
    isCheck = false;
    isOn_1 = false;
    isOn_2 = false;
    isOn_3 = false;
   
    //start 상태
    start_state = START;

    //Font 생성
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
        &font);

    id = gameStat.GetMax()+1;
}

void NewStage::Render()
{
   
    //배경, 고양이 이미지
    CatRender();

    //이름 입력 font
    RECT rc;

    rc.left = 300;
    rc.top = 800;
    rc.right = 15;
    rc.bottom = 15;

    WCHAR text[256];
    /*WCHAR abc[256] = { 0, };
    char str[256] = "초기화는 필수";
    MultiByteToWideChar(CP_ACP, 0, str, strlen(str), abc, 256);*/

    _stprintf_s<256>(text, _T("닉네임 입력: "));
    font->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
        D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

    for (int i = 0; i < cname.size(); i++)
    {
        rc.left = 600+i*35;
        rc.top = 800;
        rc.right = 750 + i * 35;
        rc.bottom = 15;

        WCHAR text[256];

        _stprintf_s<256>(text, _T("%c"), cname[i]);
        font->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
            D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
    }
    //버튼 이미지

    TextureElement* element = textureManager.GetTexture(start_state);
    element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = START_WIDTH;
    srcRect.bottom = START_HEIGHT;

    D3DXVECTOR3 pos(START_POSX, START_POSY, 0);

    if (isCheck && cname.size() > 0)
    {
        element->g_pSprite->Draw(element->g_Texture, &srcRect, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
    }
    else
    {
        element->g_pSprite->Draw(element->g_Texture, &srcRect, nullptr, &pos, D3DCOLOR_XRGB(120, 120, 120));
    }
   
    element->g_pSprite->End();

}

void NewStage::Update()
{
    //고양이 선택
    OnOff();

    //START 버튼 선택
    if (pt.x > START_POSX && pt.x<START_POSX + START_WIDTH
        && pt.y>START_POSY && pt.y < START_POSY + START_HEIGHT)
    {
        if (isCheck && cname.size() != 0)
        {
            if (inputManager.prevKey[VK_LBUTTON] == 1 && inputManager.key[VK_LBUTTON] == 0)
            {
                //이름
                std::string name(cname.begin(), cname.end());

                player.SetId(id);
                player.SetName(name);
                player.day = 1;
                player.catKind = player.GetKind();
                player.hp = MAX_HP;
                player.money = 50;
                playerInfos.push_back(player);
                gameStat.Save();


                stageManager.MakeLoadStage();

              
           }
        }
        start_state = START_BORDER;
    }
    else
    {
        start_state = START;
    }
    

    //키 입력
    if (inputManager.prevKey[VK_BACK] == 1
        && inputManager.key[VK_BACK] == 0)
    {
        if (cname.size() > 0)
        {
            cname.pop_back();
        }
    }
    else
    {
        for (int i = 'A'; i <= 'Z'; i++)
        {
            if (inputManager.prevKey[i] == 1
                && inputManager.key[i] == 0)
            {
                cname.push_back((char)i);
            }
        }
    }
}

void NewStage::OnOff()
{
    //cat1
    if (pt.x > CAT1_POSX && pt.x<CAT1_POSX + CAT_WIDTH
        && pt.y>CAT_POSY && pt.y < CAT_POSY + CAT_WIDTH)
    {
        isOn_1 = true;
        if (inputManager.prevKey[VK_LBUTTON] == 1 && inputManager.key[VK_LBUTTON] == 0)
        {
            isCheck = true;
            player.SetKind(c1);
        }

    }
    else
    {
        isOn_1 = false;
    }

    //cat2
    if (pt.x > CAT2_POSX && pt.x<CAT2_POSX + CAT_WIDTH
        && pt.y>CAT_POSY && pt.y < CAT_POSY + CAT_WIDTH)
    {
        isOn_2 = true;
        if (inputManager.prevKey[VK_LBUTTON] == 1 && inputManager.key[VK_LBUTTON] == 0)
        {
            isCheck = true;
            player.SetKind(c2);

        }

    }
    else
    {
        isOn_2 = false;
    }

    //cat3
    if (pt.x > CAT3_POSX && pt.x<CAT3_POSX + CAT_WIDTH
        && pt.y>CAT_POSY && pt.y < CAT_POSY + CAT_WIDTH)
    {
        isOn_3 = true;
        if (inputManager.prevKey[VK_LBUTTON] == 1 && inputManager.key[VK_LBUTTON] == 0)
        {
            isCheck = true;
            player.SetKind(c3);

        }

    }
    else
    {
        isOn_3 = false;

    }

    if (isOn_1 == true)
    {
        cat1_state = CAT_ON;
        cat2_state = CAT_OFF;
        cat3_state = CAT_OFF;
    }
    else if (isOn_2 == true)
    {
        cat1_state = CAT_OFF;
        cat2_state = CAT_ON;
        cat3_state = CAT_OFF;
    }
    else if (isOn_3 == true)
    {
        cat1_state = CAT_OFF;
        cat2_state = CAT_OFF;
        cat3_state = CAT_ON;
    }
    else
    {
        cat1_state = CAT_OFF;
        cat2_state = CAT_OFF;
        cat3_state = CAT_OFF;
        if (isCheck)
        {
            switch (player.GetKind())
            {
            case c1:
                cat1_state = CAT_ON;
                break;
            case c2:
                cat2_state = CAT_ON;
                break;
            case c3:
                cat3_state = CAT_ON;
                break;
            default:
                break;
            }
        }
    }
}
void NewStage::CatRender()
{
    //백그라운드
    TextureElement* element = textureManager.GetTexture(NEWSTAGE);
    element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = WINDOW_WIDTH;
    srcRect.bottom = WINDOW_HEIGHT;

    element->g_pSprite->Draw(element->g_Texture, &srcRect, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
    element->g_pSprite->End();


    //CAT1 이미지
    TextureElement* elementC1 = textureManager.GetTexture(CATN_1);
    elementC1->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

    srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = CAT_WIDTH;
    srcRect.bottom = CAT_HEIGHT;

    D3DXVECTOR3 pos1(CAT1_POSX, CAT_POSY, 0);

    if (cat1_state == CAT_ON)
        elementC1->g_pSprite->Draw(elementC1->g_Texture, &srcRect, nullptr, &pos1, D3DCOLOR_XRGB(255, 255, 255));
    else
        elementC1->g_pSprite->Draw(elementC1->g_Texture, &srcRect, nullptr, &pos1, D3DCOLOR_XRGB(120, 120, 120));
    elementC1->g_pSprite->End();

    //CAT2 이미지
    TextureElement* elementC2 = textureManager.GetTexture(CATN_2);
    elementC2->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

    srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = CAT_WIDTH;
    srcRect.bottom = CAT_HEIGHT;

    D3DXVECTOR3 pos2(CAT2_POSX, CAT_POSY, 0);
    if (cat2_state == CAT_ON)
        elementC2->g_pSprite->Draw(elementC2->g_Texture, &srcRect, nullptr, &pos2, D3DCOLOR_XRGB(255, 255, 255));
    else
        elementC2->g_pSprite->Draw(elementC2->g_Texture, &srcRect, nullptr, &pos2, D3DCOLOR_XRGB(120, 120, 120));
    elementC2->g_pSprite->End();

    //CAT3 이미지
    TextureElement* elementC3 = textureManager.GetTexture(CATN_3);
    elementC3->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

    srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = CAT_WIDTH;
    srcRect.bottom = CAT_HEIGHT;

    D3DXVECTOR3 pos3(CAT3_POSX, CAT_POSY, 0);
    if (cat3_state == CAT_ON)
        elementC3->g_pSprite->Draw(elementC3->g_Texture, &srcRect, nullptr, &pos3, D3DCOLOR_XRGB(255, 255, 255));
    else
        elementC3->g_pSprite->Draw(elementC3->g_Texture, &srcRect, nullptr, &pos3, D3DCOLOR_XRGB(120, 120, 120));
    elementC3->g_pSprite->End();

}