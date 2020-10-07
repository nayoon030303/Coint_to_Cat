#include "TextureManager.h"
#include "global.h"

void TextureManager::LoadTexture(const TCHAR* name, int id)
{
	TextureElement* newElement = new TextureElement();
	newElement->id = id;
	D3DXCreateSprite(g_pd3dDevice, &newElement->g_pSprite);
	D3DXCreateTextureFromFile(g_pd3dDevice, name, &newElement->g_Texture);
	elements.push_back(newElement);

}

TextureElement* TextureManager::GetTexture(int id)
{
	for (int i = 0; i < elements.size(); i++)
	{
		if (elements[i]->id == id)
		{
			return elements[i];
		}
	}
	return nullptr;
}