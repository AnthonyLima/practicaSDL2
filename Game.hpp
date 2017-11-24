#ifndef _gameSDL_
#define _gameSDL_

#include "Window.hpp"

//cabecera de programa donde se controla todo del juego
class Game
{
public:
	Game();
	~Game();
	void start();
	void end();

protected:
	void onAwake();
	void onInput();
	void onUpdate();
	void onRender();
	void onFinish();

protected:
	bool g_run;
	Window* g_window;
};

#endif /* gameSDL */