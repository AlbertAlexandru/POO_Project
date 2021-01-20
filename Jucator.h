#pragma once
#include "SDL.h"
#include "Vector.h"
#include "Texture.h"
#include "Keyboard.h"
#include <iostream>

class Player:public Keyboard
{
protected:
	
	SDL_Texture* jucator;
	SDL_Texture* inamic;
	SDL_Texture* arma;
	SDL_Renderer* renderer{};
	SDL_Rect srcRect{}, destRect{}; //
public:

	Player();
	Player(const char* path, SDL_Renderer* renderer,float x, float y);
	~Player()
	{
		pozitie.x = 0;
		pozitie.y = 0;
		
	};
	float speed = 1.25;

	
	void setTex(const char* path);

	void init();
	void inamicUpdate();
	void update();
	void draw();
};