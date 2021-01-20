#include<iostream>
#include "Joc.h"


using namespace std;


Joc::Joc():isRunning(false), window(nullptr), renderer(nullptr)
{
}

Joc::~Joc()
{	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	isRunning = false;
	SDL_Quit();
}


void Joc::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flag = 0;
	if (fullscreen)
	{
		flag = SDL_WINDOW_FULLSCREEN;
	}
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "Subsistem initializat" << endl;
		auto window = SDL_CreateWindow(title, xpos, ypos, width, height, flag); //Creeaza un Window la pozitia (xpos,ypos) de dimensiuni (width, height)
		if (window != nullptr)
		{
			cout << "Fereastra creata" << endl;
		}
		else
		{
			isRunning = false;
			cout << "Esuare la crearea ferestrei" << SDL_GetError() << endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0); //Componenta de randare 2D atasata unui Window;
		if (renderer != nullptr)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);//culoare pentru desenare
			cout << "Renderer creat" << endl;
		}
		else
		{
			isRunning = false;
			cout << "Esuare de creare renderer " << SDL_GetError() << endl;
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
		cout << "Esuare de initializare: " << SDL_GetError() << endl;
	}
	
	meniu = new MeniuPrincipal(renderer);
	Map1 = new Map(renderer);
	
	

	player1 = new Player("assets/walk 1.png", renderer,16.0f,512.0);
	player1->init();
	


	
	inamic1 = new Player("assets/enemy2.png", renderer, 1024, 345.0f);
	inamic2 = new Player("assets/enemy3.png", renderer, 512, 650.0f);
	inamic3 = new Player("assets/enemy4.png", renderer, 800, 512.0f);

	inamic4 = new Player("assets/enemy2.png", renderer, 2* 1024, 345.0f);
	inamic5 = new Player("assets/enemy3.png", renderer, 3 * 512, 650.0f);
	inamic6 = new Player("assets/enemy4.png", renderer, 2 * 800, 512.0f);

	inamic7 = new Player("assets/enemy2.png", renderer, 2 * 1024, 345.0f);
	inamic8 = new Player("assets/enemy3.png", renderer, 4 * 512, 650.0f);
	inamic9 = new Player("assets/enemy4.png", renderer, 2 * 800, 512.0f);

	inamic10 = new Player("assets/enemy2.png", renderer, 3* 1024, 345.0f);
	inamic11 = new Player("assets/enemy3.png", renderer, 5 * 512, 650.0f);
	inamic12 = new Player("assets/enemy4.png", renderer, 3 * 800, 512.0f);

	inamica4 = new Player("assets/enemy2.png", renderer, 4 * 1024, 345.0f);
	inamica5 = new Player("assets/enemy3.png", renderer, 6 * 512, 650.0f);
	inamica6 = new Player("assets/enemy4.png", renderer, 4 * 800, 512.0f);

	inamica7 = new Player("assets/enemy2.png", renderer, 5 * 1024, 345.0f);
	inamica8 = new Player("assets/enemy3.png", renderer, 7 * 512, 650.0f);
	inamica9 = new Player("assets/enemy4.png", renderer, 5 * 800, 512.0f);

	inamica10 = new Player("assets/enemy2.png", renderer, 6*1024, 345.0f);
	inamica11 = new Player("assets/enemy3.png", renderer, 8*512, 650.0f);
	inamica12 = new Player("assets/enemy4.png", renderer, 6*800, 512.0f);

	inamic1->init();
	inamic2->init();
	inamic3->init();
	inamic4->init();
	inamic5->init();
	inamic6->init();
	inamic7->init();
	inamic8->init();
	inamic9->init();
	inamic10->init();
	inamic11->init();
	inamic12->init();
	inamica4->init();
	inamica5->init();
	inamica6->init();
	inamica7->init();
	inamica8->init();
	inamica9->init();
	inamica10->init();
	inamica11->init();
	inamica12->init();
}

void Joc::Events()
{
	SDL_Event eveniment;
	SDL_PollEvent(&eveniment);
	switch (eveniment.type)
	{
	case SDL_QUIT: {
		isRunning = false;
		break;
	}
	default:
		break;
	}
}
void Joc::update() //update in timp real
{
	
	
	player1->PressKey();
	player1->update();

	
	inamic1->inamicUpdate();
	inamic2->inamicUpdate();
	inamic3->inamicUpdate();
	inamic4->inamicUpdate();
	inamic5->inamicUpdate();
	inamic6->inamicUpdate();
	inamic7->inamicUpdate();
	inamic8->inamicUpdate();
	inamic9->inamicUpdate();
	inamic10->inamicUpdate();
	inamic11->inamicUpdate();
	inamic12->inamicUpdate();
	inamica4->inamicUpdate();
	inamica5->inamicUpdate();
	inamica6->inamicUpdate();
	inamica7->inamicUpdate();
	inamica8->inamicUpdate();
	inamica9->inamicUpdate();
	inamica10->inamicUpdate();
	inamica11->inamicUpdate();
	inamica12->inamicUpdate();

	
}
void Joc::renderMeniu()
{
	SDL_RenderClear(renderer);

	meniu->DrawMeniu();
	SDL_RenderPresent(renderer);
}
void Joc::renderJoc() //vom randa obiectele
{
	SDL_RenderClear(renderer);
	Map1->DrawMap();

		inamic1->draw();
		inamic2->draw();
		inamic3->draw();
		inamic4->draw();
		inamic5->draw();
		inamic6->draw();
		inamic7->draw();
		inamic8->draw();
		inamic9->draw();
		inamic10->draw();
		inamic11->draw();
		inamic12->draw();
		inamica4->draw();
		inamica5->draw();
		inamica6->draw();
		inamica7->draw();
		inamica8->draw();
		inamica9->draw();
		inamica10->draw();
		inamica11->draw();
		inamica12->draw();

	player1->draw();
	SDL_RenderPresent(renderer);
	
	
}
void Joc::cleanMeniu()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Joc curatat" << endl;
}
void Joc::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete inamic1;
	delete inamic2;
	delete inamic3;
	delete inamic4;
	delete inamic5;
	delete inamic6;
	delete inamic7;
	delete inamic8;
	delete inamic9;
	delete inamic10;
	delete inamic11;
	delete inamic12;
	delete inamica4;
	delete inamica5;
	delete inamica6;
	delete inamica7;
	delete inamica8;
	delete inamica9;
	delete inamica10;
	delete inamica11;
	delete inamica12;
	delete player1;
	delete Map1;
	SDL_Quit();
	cout << "Joc curatat" << endl;
}