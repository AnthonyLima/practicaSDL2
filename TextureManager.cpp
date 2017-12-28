#include "TextureManager.hpp"

TextureManager::TextureManager()
{}

TextureManager::~TextureManager()
{}

/*este procedimiento hace uso de la libreria SDL2_image para transformar imagenes
  de extension PNG a textura requiere del render que se trabaja en la pantalla*/
SDL_Texture* TextureManager::loadTexture(const char* fileName)
{
	SDL_Texture* tex = IMG_LoadTexture(Window::w_renderer, fileName);

	return tex;
}

void TextureManager::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Window::w_renderer, tex, &src, &dest);
}