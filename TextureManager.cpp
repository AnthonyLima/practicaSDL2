#include "TextureManager.hpp"

TextureManager::TextureManager()
{}

TextureManager::~TextureManager()
{}

/*este procedimiento hace uso de la libreria SDL2_image para transformar imagenes
  de extension PNG a textura requiere del render que se trabaja en la pantalla*/
SDL_Texture* TextureManager::loadTexture(const char* fileName, SDL_Renderer* ren)
{
	SDL_Texture* tex = IMG_LoadTexture(ren, fileName);

	return tex;
}