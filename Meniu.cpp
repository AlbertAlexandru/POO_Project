#include "Meniu.h"
#include "Joc.h"
#include "Texture.h"
#include <SDL.h>
#include <iostream>
using namespace std;
int map[1][1] = { 1 };
MeniuPrincipal::MeniuPrincipal(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	background = Texture::incarcaTextura("assets/backgroundMeniu.png", renderer);
	start = Texture::incarcaTextura("assets/space.png", renderer);
	IncarcaMeniu(map);

	src.x = 0;
	src.y = 0;
	src.w = src.h = 32;
	dest.x = 0;
	dest.y = 0;
	dest.w = 840;
	dest.h = 640;
}
MeniuPrincipal::~MeniuPrincipal()
{
	delete background;

	delete start;

}

void MeniuPrincipal::IncarcaMeniu(int meniu[1][1])
{
	map[1][1] = meniu[1][1];
}

void MeniuPrincipal::DrawMeniu()
{
	int m = 0;
	for (int i = 0; i < 1; ++i)
	{
		for (int j = 0; j < 1; ++j)
		{
			m = Meniu[j][i];

			dest.x = i * 64;
			dest.y = j * 32;
			switch (m)
			{
			case 0:
			{
				Texture::Init(background, src, dest, renderer);
				Texture::Init(start, src, dest, renderer);
				break;
			}
			
			default:
				break;
			}
		}
	}

	
}