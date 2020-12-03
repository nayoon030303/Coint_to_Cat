#include "runPlayer.h"
#include "global.h"

#define JUMP_Y  400
#define BOTTON_Y  780

RunPlayer::RunPlayer()
{
	playerX = 300;
	playerY = 780;
	
	isBottom = true;
	isJump = false;
}

void RunPlayer::Render()
{
	//cat
	TextureElement* element = textureManager.GetTexture(player.GetKind() * 10);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = CAT_WIDTH;
	rc.bottom = CAT_HEIGHT;

	D3DXVECTOR3 pos(playerX, playerY, 0);
	D3DXVECTOR3 cen(CAT_WIDTH / 2, CAT_HEIGHT / 2, 0);

	element->g_pSprite->Draw(element->g_Texture, &rc, &cen, &pos, D3DCOLOR_XRGB(255, 255, 255));
	element->g_pSprite->End();
}

void RunPlayer::Update()
{

	if (inputManager.prevKey[VK_UP] == 1 && inputManager.key[VK_UP] == 0 && isBottom) {
		isJump = true;
		isBottom = false;

	}

	if (isJump) {
		playerY -= 20;
	}

	if (!isJump && !isBottom){
		playerY += 18;
	}

	if (playerY < JUMP_Y) {
		isJump = false;
		playerY = JUMP_Y;
	}
	if (playerY >=BOTTON_Y) {
		isBottom = true;
		playerY = BOTTON_Y;
	}

}

