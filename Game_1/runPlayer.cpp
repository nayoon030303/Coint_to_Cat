#include "runPlayer.h"
#include "global.h"

#define JUMP_Y  400


RunPlayer::RunPlayer()
{
	playerX = 150.0f;
	playerY = 780.0f;
	
	isBottom = true;
	isJump = false;
	
	jumpPower = 40.0f;
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

	if (inputManager.key[VK_SPACE] == 1 &&  !isJump) {
		isJump = true;
	}
	
	if (isJump) {
		Jump();
	}
	playerY = 780.0f;
	playerY += jumpHeight;
	
}

void RunPlayer::Jump()
{
	//이차함수
	
	jumpHeight = jumpTime * jumpTime - jumpPower * jumpTime;

	jumpTime += 0.8f;

	if (jumpTime >= jumpPower) 
	{
		jumpTime = 0.f;
		jumpHeight = 0.f;

		isJump = false;
	}
}