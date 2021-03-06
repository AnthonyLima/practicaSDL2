#ifndef _ventanaSDL_
#define _ventanaSDL_

#include <SDL2/SDL.h>
#include <string>
#include <iostream>

class Window
{
public:
	Window(int width, int height);
	~Window();
	void mostrarVentana();
	void destruirVentana();
	void limpiarRender();
	void mostrarRender();
	static SDL_Renderer* w_renderer;

private:
	int w_width;
	int w_height;
	SDL_Window* w_window;
};

#endif /* ventanaSDL */