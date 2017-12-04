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
{
	SDL_RenderCopy(objRenderer,objTexture,&srcRect,&desRect);
}

void GameObject::update()
{
	this->changeDest();
}

void GameObject::changeDest()
{
	desRect.x = xPos;
	desRect.y = yPos;
	desRect.h = srcRect.h * 2;
	desRect.w = srcRect.w * 2;
}

void GameObject::changePosX(int	cant)
{
	xPos = xPos + cant;
}

void GameObject::changePosY(int cant)
{
	yPos = yPos + cant;
}
