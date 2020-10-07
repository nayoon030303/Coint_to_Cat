#include "global.h"
#include "MainStage.h"

MainStage::MainStage()
{

}

void MainStage::Render()
{
    TextureElement* element = textureManager.GetTexture(MAINSTAGE);
    element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = WINDOW_WIDTH;
    srcRect.bottom = WINDOW_HEIGHT;

    element->g_pSprite->Draw(element->g_Texture, &srcRect, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
    element->g_pSprite->End();
}

void MainStage::Update()
{
    if (inputManager.prevKey[VK_LBUTTON] == 1 && inputManager.key[VK_LBUTTON] == 0)
    {
        stageManager.MakeTitleStage();
    }


}