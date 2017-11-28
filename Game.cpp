#include "Game.hpp"
#include "Window.cpp"
#include "GameObject.cpp"

//limitar cuadros por segundo
const int fps = 60;
const int frameDelay = 1000/fps;
Uint32 frameStart;
int frameTime;

GameObject* objPrueba;

Game::Game()
{}

Game::~Game()
{}

void Game::start()
{
	g_run = true;
	onAwake();
	while(g_run)
	{
		frameStart = SDL_GetTicks();

		onInput();
		onUpdate();
		onRender();

		frameTime = SDL_GetTicks() - frameStart;
		if(frameDelay > frameTime)
			SDL_Delay(frameDelay - frameTime);
	}
	onFinish();
}

void Game::end()
{
	g_run = false;
}

//procedimiento de inicio
void Game::onAwake()
{
	SDL_Init(SDL_INIT_VIDEO);
	g_window = new Window(800,600);

	//realiza los procedimientos de sdl2 para crear la ventana, por defecto hace uso de OpenGL
	g_window->mostrarVentana();

	objPrueba = new GameObject("sprites/navePrueba.png",g_window->w_renderer,100,100,50,50);
}

//eliminacion de recursos utilizados
void Game::onFinish()
{
	g_window->destruirVentana();
	SDL_Quit();
}

//proceso de captura de acciones del jugador
void Game::onInput()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
				this->end();
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						this->end();
						break;
				}
				break;
			default:
				break;
		}
	}
}

void Game::onUpdate()
{
	objPrueba->update();
}

//procedimiento de recargar la pantalla con la nueva informacion
void Game::onRender()
{
	g_window->limpiarRender();
	objPrueba->render();
	g_window->mostrarRender();
}