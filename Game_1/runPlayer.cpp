#include "runPlayer.h"
#include "global.h"

#define JUMP_Y  400


RunPlayer::RunPlayer()
{
	playerX = 150.0f;
	playerY = BOTTOM_Y - CAT_HEIGHT;
	isBottom = true;
	isJump = false;
	jumpPower = 40.0f;
	score = 0;
	isDead = false;
	isHit = false;
	width = CAT_WIDTH;
	height = CAT_HEIGHT;
	isGameOver = false;
}

void RunPlayer::Render()
{
	//cat
	TextureElement* element = textureManager.GetTexture(player->GetKind() * 10);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT rc;
	if (isDown)
	{
		height = CAT_HEIGHT / 2;
		rc.left = 150;
		rc.top = 0;
		rc.right = width+150;
		rc.bottom = height;
		playerY = BOTTOM_Y - height;
	}
	else
	{
		rc.left = 0;
		rc.top = 0;
		rc.right = width;
		rc.bottom = height;
	}
	
	if (isDead)
	{
		rc.left = 300;
		rc.top = 0;
		rc.right = width+300;
		rc.bottom = height;
	}
	
	D3DXVECTOR3 pos(playerX, playerY, 0);
	//D3DXVECTOR3 cen(CAT_WIDTH / 2, CAT_HEIGHT / 2, 0);

	if (isHit == true) {
		element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, &pos, D3DCOLOR_XRGB(255, 0, 255));
	}
	else {
		element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
	}

	
	element->g_pSprite->End();
}

void RunPlayer::Update()
{
	if (!isDead)
	{
		if (inputManager.key[VK_UP] == 1 && !isJump) {
			isJump = true;
		}
		else if (inputManager.key[VK_DOWN] == 1 && !isJump)
		{
			isDown = true;
		}
		else if (inputManager.prevKey[VK_DOWN]==1 && inputManager.key[VK_DOWN] == 0)
		{
			height = CAT_HEIGHT;
			isDown = false;
			playerY = BOTTOM_Y - height;
		}
		

		if (isJump) {
			Jump();
		}
		//playerY = ;
		playerY = BOTTOM_Y - height + jumpHeight;
	}
	if (isDead)
	{
		time++;
		if (time > 20)
		{
			isGameOver = true;
		}
	}
	
}

void RunPlayer::Jump()
{
	//이차함수
	
	jumpHeight = jumpTime * jumpTime - jumpPower * jumpTime;

	jumpTime += 1.0f;

	if (jumpTime >= jumpPower) 
	{
		jumpTime = 0.f;
		jumpHeight = 0.f;

		isJump = false;
	}
}

void RunPlayer::AddScore()
{
	score += 1;
 }

void RunPlayer::isHITED()
{
	isHit = true;
}