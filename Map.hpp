#ifndef _Map_
#define _Map_

#include "Window.hpp"

class Map
{
public:
	Map();
	~Map();
	void loadMap(int arr[20][25]);
	void drawMap();

private:
	SDL_Rect src, dest;
	SDL_Texture* floor;
	SDL_Texture* wall;
	SDL_Texture* brick;
	int map[20][25]; //las imagenes seran 50x40 pixeles, cantidad 16x15
};

#endif /* Map */