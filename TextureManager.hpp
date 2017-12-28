#ifndef _TextureManager_
#define _TextureManager_

#include "Window.hpp"
#include <SDL2/SDL_image.h>

class TextureManager
{
public:
	TextureManager();
	~TextureManager();
	static SDL_Texture* loadTexture(const char* fileName);
	static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
private:
};

#endif /* TextureManager */