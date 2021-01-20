#include "Texture.h"
#include "SDL_image.h"
#include "SDL.h"

SDL_Texture* Texture::incarcaTextura(const char* file, SDL_Renderer* renderer)
{
	SDL_Surface* tempSurface = IMG_Load(file);//incarca imaginea// SDL Surface utilizeaza CPu pt randare
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempSurface);//stocheaza informatia despre pixelii elementului
	SDL_FreeSurface(tempSurface);
	return tex;
}

void Texture::Init(SDL_Texture* textura, SDL_Rect src, SDL_Rect dest, SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, textura, nullptr, &dest);//initializam cu pointer null;fi
}
