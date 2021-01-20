#pragma once
#include "SDL_image.h"
#include "Texture.h"
#include <SDL.h>
class Map
{
private:
	SDL_Renderer* renderer;
	SDL_Rect src, dest;
	SDL_Texture* backgroundJoc;
	SDL_Texture* b1;
	SDL_Texture* b2;
	SDL_Texture* b3;
	SDL_Texture* b4;
	SDL_Texture* b5;

	int map[4][1];
public:
	Map(SDL_Renderer* renderer);
	~Map();

	void LoadMap(int harta[4][1]);
	void DrawMap();
};
