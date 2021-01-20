#include<SDL.h>
#include"Joc.h"

#include<iostream>
using namespace std;

const int ScreenWidth = 1680;
const int ScreenHeight = 960;


int main(int argc, char* argv[])
{
	Joc* game = new Joc();
	Joc* meniu = new Joc();
	const int fps = 60;
	const int fpsDelay = 1000 / fps;
	bool run = true;
	SDL_Event event1;
	SDL_Event event2;
	meniu->init("Joc Poo", 450, 150, 840, 640, false);
	cout << "\n \nREGULI JOC: " << endl;
	cout << "\n\n\t 1. COMEZNI: Pentru a va deplasa folositi combinatiile de taste << <W, A, S, D> >>!";  
	cout << "\n\t\t     Prin apasarea tastei << <ESC> >> (escape) jocul va fi parasit (QUIT GAME)!";
	cout<<" \n\t\t     Pentru a lansa jocul apasati tasta SPACE << <SPACE >> > !\n";
	cout << "\n\t 2. DESCRIERE JOC: Jocul este unul simplu, personajul principal este un soldatel\n\t\t\t   care trebuie sa se deplaseze pe harta pentru a elimina monstrii care il ataca.";
	cout<<"\n\t\t\t   Scopul final este de a omori cati mai multi inamici si de a aduna maximul de puncte\n\n\n";
while (meniu->running() && run==true)
	{

		Uint32 frameStart = SDL_GetTicks();
		meniu->Events();
		meniu->renderMeniu();

		const int frameTime = SDL_GetTicks() - frameStart;

		if (fpsDelay > frameTime)
		{
			SDL_Delay(fpsDelay - frameTime);
		}
		if (SDL_PollEvent(&event1))
		{
			if (event1.type == SDL_KEYDOWN)
			{
				switch (event1.key.keysym.sym)
				{
				case SDLK_SPACE:
					{
					
					game->init("Joc Poo", 100, 50, ScreenWidth, ScreenHeight, false);
					
					while (game->running()) //cat timp jocul ruleaza
					{
						
						Uint32 frameStart = SDL_GetTicks();
						game->Events();
						game->renderJoc();

						const int frameTime = SDL_GetTicks() - frameStart;

						if (fpsDelay > frameTime)
						{
							SDL_Delay(fpsDelay - frameTime);
						}
						game->update();
						

						
					}
					
					break;
					}
				case SDLK_ESCAPE:
				{
					return -1;
					meniu->clean();
					delete meniu;
					cout << "\nParasire joc \n";
					break;
				}
				}
			}
			else if (event1.type == SDL_QUIT)
			{
				SDL_Quit();
				meniu->clean();
				delete meniu;
			}
		}
		
	}
game->clean();
delete game;
	
system("PAUSE");
	
	
	
	return 0;
}