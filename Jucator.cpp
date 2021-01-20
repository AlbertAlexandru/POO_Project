#include"Jucator.h"


Player::Player(const char* path, SDL_Renderer* renderer, float x, float y) :renderer(renderer)
{
	
	pozitie.x = x;
	pozitie.y = y;
	setTex(path);
	
}


void Player::setTex(const char* path)
{


	jucator = Texture::incarcaTextura(path, renderer);
	inamic = Texture::incarcaTextura(path, renderer);
}

void Player::init()
{
	

	srcRect.x = pozitie.x;//sursa
	srcRect.y = pozitie.x;
	destRect.x = pozitie.x;//destinatie
	destRect.y = pozitie.y;
	srcRect.w = srcRect.h = 64;
	destRect.w = destRect.h = 128;
	viteza.x = 0;
	viteza.y = 0;
}


void Player::update()
{
	destRect.x += viteza.x * (speed + 2);
	destRect.y += viteza.y * (speed + 2);
	
	

}

void Player::inamicUpdate()
{
	destRect.x -= (int)speed;
}

void Player::draw()
{
	Texture::Init(inamic, srcRect, destRect, renderer);
	Texture::Init(jucator, srcRect, destRect, renderer);
}

