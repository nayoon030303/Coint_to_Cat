#include "musicPlayer.h"
#include "global.h"

MusicPlayer::MusicPlayer()
{
	score = 0;
	hp = 3;
	isFinish = false;
	width = CAT_WIDTH;
	height = CAT_HEIGHT;
}

void MusicPlayer::Render()
{
	TextureElement* element = textureManager.GetTexture(player->GetKind() * 10);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;

	D3DXVECTOR3 pos(950, 680, 0);

	element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
	element->g_pSprite->End();

}

void MusicPlayer::Update()
{
	if (hp <= 0)
	{
		isFinish = true;
		isGameOver = true;
	}
}

void MusicPlayer::MinusHp()
{
	hp--;
}
void MusicPlayer::AddScore()
{
	score+=2;
}