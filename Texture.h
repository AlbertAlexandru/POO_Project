#pragma once
#include "SDL_image.h"
#include "SDL.h"
class Texture
{
	protected:
	 const char* file;
	 SDL_Renderer* renderer;
	 SDL_Texture* textura{};
public: 
	
	static SDL_Texture* incarcaTextura(const char* file, SDL_Renderer* renderer);
	static void Init(SDL_Texture* textura, SDL_Rect src, SDL_Rect dest, SDL_Renderer* renderer);
};