#include "TitleStage.h"
#include "global.h"
#include "StageManager.h"

#define BUTTON_X 887
#define NEW_BUTTON_Y 467
#define LOAD_BUTTON_Y 650
#define EXIT_BUTTON_Y 3

#define BUTTON_WIDTH 311
#define BUTTON_HEIGHT 115

TitleStage::TitleStage()
{

}

void TitleStage::Render()
{
	TextureElement* element = textureManager.GetTexture(TITLE);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = WINDOW_WIDTH;
    srcRect.bottom = WINDOW_HEIGHT;

    element->g_pSprite->Draw(element->g_Texture, &srcRect, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
    element->g_pSprite->End();

}

void TitleStage::Update()
{
    //new 버튼
    if (pt.x > BUTTON_X && pt.x<BUTTON_X + BUTTON_WIDTH
        && pt.y>NEW_BUTTON_Y && pt.y < NEW_BUTTON_Y + BUTTON_HEIGHT)
    {
        if (inputManager.prevKey[VK_LBUTTON]==1 && inputManager.key[VK_LBUTTON] == 0)
        {
            stageManager.MakeNewStage();
        }
       
    }

    //load 버튼
    if (pt.x > BUTTON_X && pt.x<BUTTON_X + BUTTON_WIDTH
        && pt.y>LOAD_BUTTON_Y && pt.y < LOAD_BUTTON_Y + BUTTON_HEIGHT)
    {
        if (inputManager.prevKey[VK_LBUTTON] == 1 && inputManager.key[VK_LBUTTON] == 0)
        {
            stageManager.MakeLoadStage();
        }

    }
    
}