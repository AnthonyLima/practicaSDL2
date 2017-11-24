#include "Game.hpp"
#include "Window.cpp"

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
		onInput();
		onUpdate();
		onRender();
	}
	onFinish();
}

void Game::end()
{
	g_run = false;
}

void Game::onAwake()
{
	SDL_Init(SDL_INIT_VIDEO);
	g_window = new Window(800,600);
	g_window->mostrarVentana();
}

void Game::onFinish()
{
	g_window->destruirVentana();
	SDL_Quit();
}

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
{}

void Game::onRender()
{
	g_window->limpiarRender();
	g_window->mostrarRender();
}