#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include "Texture.h"


class MeniuPrincipal
{
private:
	bool isRunning;
	SDL_Texture* background;
	SDL_Texture* start;
	SDL_Renderer* renderer;
	SDL_Rect src, dest;
	int Meniu[1][1];
public:
	MeniuPrincipal(SDL_Renderer* renderer);
	~MeniuPrincipal();

	void IncarcaMeniu(int meniu[1][1]);
	void DrawMeniu();
	bool running() {
		return isRunning;
	}

};
