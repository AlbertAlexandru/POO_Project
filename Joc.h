#pragma once
#include<iostream>
#include <SDL.h>
#include"Meniu.h"
#include "Jucator.h"
#include "Joc.h"
#include "Map.h"
#include "Vector.h"
#include "Keyboard.h"
class Joc
{
private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	MeniuPrincipal* meniu = nullptr;

	Map* Map1 = nullptr;

	Player* player1 = nullptr;
	Player* inamic1 = nullptr;
	Player* inamic2 = nullptr;
	Player* inamic3 = nullptr;
	Player* inamic4 = nullptr;
	Player* inamic5 = nullptr;
	Player* inamic6 = nullptr;
	Player* inamic7 = nullptr;
	Player* inamic8 = nullptr;
	Player* inamic9 = nullptr;
	Player* inamic10 = nullptr;
	Player* inamic11 = nullptr;
	Player* inamic12 = nullptr;
	Player* inamica4 = nullptr;
	Player* inamica5 = nullptr;
	Player* inamica6 = nullptr;
	Player* inamica7 = nullptr;
	Player* inamica8 = nullptr;
	Player* inamica9 = nullptr;
	Player* inamica10 = nullptr;
	Player* inamica11 = nullptr;
	Player* inamica12 = nullptr;
	Player* arma = nullptr;
	int speed = 5;
public:
	Joc();
	~Joc();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen=false);
	
	
	void Events();
	void update();

	void renderMeniu();
	void renderJoc();

	void clean();
	void cleanMeniu();

	bool running()
	{
		return isRunning;
	}

};