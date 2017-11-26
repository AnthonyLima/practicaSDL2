#ifndef _GameObject_
#define _GameObject_

#include "Window.hpp"
#include "TextureManager.hpp"

class GameObject
{
public:
	GameObject(const char* pngFile, SDL_Renderer* ren, int x, int y, int widthObject, int heightObject);
	~GameObject();
	void render();
	void update();
private:
	int xPos;
	int yPos;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, desRect;
	SDL_Renderer* objRenderer;
};

#endif