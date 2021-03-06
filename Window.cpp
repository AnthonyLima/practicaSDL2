#include "Window.hpp"

using namespace std;

SDL_Renderer* Window::w_renderer = nullptr;

//constructor de la ventana indicando las dimensiones
Window::Window(int width, int height):w_width(width),w_height(height)
{}

Window::~Window()
{
	destruirVentana();
}

//procedimiento de creacion de la ventana y renderizado
void Window::mostrarVentana()
{
	if(w_window != NULL)
	{
		string title;
		int posX;
		int posY;
		int windowType;

		title = "motorSDL";
		posX = SDL_WINDOWPOS_CENTERED;
		posY = SDL_WINDOWPOS_CENTERED;
		windowType = SDL_WINDOW_OPENGL;

		w_window = SDL_CreateWindow(title.c_str(), posX, posY, w_width, w_height, windowType);

		int rendererIndex;
		int rendererType;

		rendererIndex = 0;
		rendererType = SDL_RENDERER_ACCELERATED;

		w_renderer = SDL_CreateRenderer(w_window,rendererIndex,rendererType);
	}
}

void Window::destruirVentana()
{
	SDL_DestroyRenderer(w_renderer);
	SDL_DestroyWindow(w_window);
}

void Window::limpiarRender()
{
	SDL_RenderClear(w_renderer);
}

void Window::mostrarRender()
{
	SDL_RenderPresent(w_renderer);
}