#ifndef _TextureManager_
#define _TextureManager_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager
{
public:
	TextureManager();
	~TextureManager();
	static SDL_Texture* loadTexture(const char* fileName, SDL_Renderer* ren);
private:
};

#endif /* TextureManager */