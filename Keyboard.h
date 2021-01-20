#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Vector.h"
#include <iostream>
using namespace std;
class Keyboard
{
protected:
	Vector viteza;
	Vector pozitie;

	SDL_Renderer* renderer;
public:

	Keyboard() = default;
	~Keyboard() = default;

	void PressKey()
	{
		SDL_Event e;

		if (SDL_PollEvent(&e))
		{
			if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_d:
				{
					viteza.x = 1;
					std::cout << "Tasta D apasata" << endl;
					break;
				}
				case SDLK_w:
				{
					viteza.y = -1;
					std::cout << "Tasta W apasata" << endl;
					break;
				}
				case SDLK_s:
				{
					viteza.y = 1;
					std::cout << "Tasta S apasata" << endl;
					break;
				}
				case SDLK_a:
				{
					viteza.x = -1;
					std::cout << "Tasta A apasata" << endl;
					break;
				}
				case SDLK_ESCAPE:
				{
					std::cout << "Tasta ESCAPE apasata" << endl<<"Parasire joc \n";
					SDL_Quit();
					break;
				}


				}

			}
			else if (e.type == SDL_KEYUP)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_a: viteza.x = 0;   break;
				case SDLK_d: viteza.x = 0;   break;
				case SDLK_w: viteza.y = 0;  break;
				case SDLK_s: viteza.y = 0;  break;
				default: break;
				}
			}

			else if (e.type == SDL_QUIT)
			{
				SDL_Quit();
			}
		}
	};

};

