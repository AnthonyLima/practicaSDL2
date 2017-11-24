#include "Game.hpp"
#include "Window.cpp"

Game::Game()
{}

Game:~Game()
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
	g_window->show();
}

void Game::onFinish()
{
	g_window->hide();
	SDL_QUIT();
}

void Game::onInput()
{}

void Game::onUpdate()
{}

void Game::onRender()
{}