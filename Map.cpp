#include "Map.h"



int a[5][1] = {
	{ 2 },
	{1},
	{3},
	{4},
	{5}
};
Map::Map(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	
	b1 = Texture::incarcaTextura("assets/1.png", renderer);
	b2 = Texture::incarcaTextura("assets/2.png", renderer);
	b3 = Texture::incarcaTextura("assets/3.png", renderer);
	b4 = Texture::incarcaTextura("assets/4.png", renderer);
	b5 = Texture::incarcaTextura("assets/5.png", renderer);
	LoadMap(a);

	src.x = 0;
	src.y = 0;
	src.w = 32;
	src.h = 32;
	dest.x = 0;
	dest.y = 0;
	dest.w = 1680;
	dest.h = 960;
}
Map::~Map()
{
	SDL_DestroyTexture(b1);
	SDL_DestroyTexture(b2);
	SDL_DestroyTexture(b3);
	SDL_DestroyTexture(b4);
	SDL_DestroyTexture(b5);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
void Map::LoadMap(int harta[4][1])
{
	a[4][1] = harta[4][1];
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 1; ++j)
		{
			map[i][j] = harta[i][j];
		}
	}
}

void Map::DrawMap()
{
	int a=0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 1; ++j)
		{
			a = map[j][i];

			dest.x = i * 0;
			dest.y = j * 1;
			switch (a)
			{
			case 1:
				{
				Texture::Init(b3, src, dest, renderer);
				Texture::Init(b2, src, dest, renderer);
				Texture::Init(b1, src, dest, renderer);
				Texture::Init(b4, src, dest, renderer);
				Texture::Init(b5, src, dest, renderer);
				break;
				}
			
			default:
				break;
			}
		}
	}
}