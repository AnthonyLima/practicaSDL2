#include "GameObject.hpp"

GameObject::GameObject(const char* pngFiel, SDL_Renderer* ren, int x, int y, int widthObject, int heightObject)
{
	objRenderer = ren;
	objTexture = TextureManager::loadTexture(pngFiel,ren);
	xPos = x;
	yPos = y;

	srcRect.w = widthObject;
	srcRect.h = heightObject;
	srcRect.x = 0;
	srcRect.y = 0;
}

GameObject::~GameObject()
{}

void GameObject::render()
{}

void GameObject::update()
{}