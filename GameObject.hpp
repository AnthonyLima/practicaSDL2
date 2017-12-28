#ifndef _GameObject_
#define _GameObject_

#include "Window.hpp"
#include "TextureManager.cpp"

class GameObject
{
public:
	GameObject(const char* pngFile, int x, int y, int widthObject, int heightObject);
	~GameObject();
	void render();
	void update();
	void changePosX(int cant);
	void changePosY(int cant);
protected:
	void changeDest();
private:
	int xPos;
	int yPos;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, desRect;
};

#endif
