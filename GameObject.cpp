#include "GameObject.hpp"

//contructor de los objetos del juego
//tener en consideracion las dimensiones exactas y conversiones si desean aumentar o reducir la imagen
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
	
	this->changeDest();
}

GameObject::~GameObject()
{}

void GameObject::render()
{
	SDL_RenderCopy(objRenderer,objTexture,&srcRect,&desRect);
}

void GameObject::update()
{
	//this->changeDest();
}

//espacio que sera puesta la textura del objeto en pantalla
void GameObject::changeDest()
{
	desRect.x = xPos;
	desRect.y = yPos;
	desRect.h = srcRect.h * 2;
	desRect.w = srcRect.w * 2;
}

//cambio de coordenada X del objeto
void GameObject::changePosX(int	cant)
{
	xPos = xPos + cant;
	if(cant > 0)
	{
		srcRect.x = 25;
	}
	else
	{
		srcRect.x = 75;
	}
	this->changeDest();
}

//cambio de coordenada Y del objeto
void GameObject::changePosY(int cant)
{
	yPos = yPos + cant;
	if(cant > 0)
	{
		srcRect.x = 50;
	}
	else
	{
		srcRect.x = 0;
	}
	this->changeDest();
}
