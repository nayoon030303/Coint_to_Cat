#pragma once
#include <vector>
#include <d3dx9.h>

using namespace std;

class TextureElement
{
public:
	int id;
	LPDIRECT3DTEXTURE9  g_Texture;
	ID3DXSprite* g_pSprite;
};

class TextureManager
{
public:
	vector<TextureElement*> elements;
	void LoadTexture(const TCHAR* name, int id);
	TextureElement* GetTexture(int id);
};