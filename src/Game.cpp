/*
 * Game.cpp
 *
 *  Created on: Apr 24, 2018
 *      Author: eliro
 */

#include "Game.h"
#include "textureManager.h"
#include "ECS/Components.h"
#include "ZombieManager.h"
//#include "ECS/KeyBoardController.h"
#include "Vector2D.h"
#include <iostream>


SDL_Event Game::e;
SDL_Renderer* Game::renderer =NULL;
Manager Game::manager;
Entity& Game::Map(Game::manager.addEntity());

ZombieManager* zombieManager;
//Entity& Game::Map=mapa;
auto& Player(Game::manager.addEntity());
auto& Enemy(Game::manager.addEntity());
auto& Ally(Game::manager.addEntity());

Game::Game() {
	// TODO Auto-generated constructor stub
	window = NULL;
	renderer = NULL;
	backgroundTex = NULL;
	running = false;
	cnt =0;

}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

void Game::init(const char* title, int xpos, int ypos,int width, int height, bool fullscreen)
{
	//SCREEN_WITDH = width;
	//SCREEN_HEIGHT = height;
	int flag =0;
	if(fullscreen)
		flag =SDL_WINDOW_FULLSCREEN;
	if(SDL_Init(SDL_INIT_EVERYTHING)==0)
	{
		std::cout<<"Subsystem initialize"<<std::endl;
		window =SDL_CreateWindow(title, xpos, ypos, width, height,flag);
		if(window)
		{
			std::cout<<"Window initialized"<<std::endl;
		}
		renderer = SDL_CreateRenderer(window,-1,0);
		if(renderer)
		{
			SDL_SetRenderDrawColor(renderer,255,255,255,255);
			std::cout<<"Renderer created"<<std::endl;
		}
		running = true;
	}
	//std::cout<<"mapa: "<<&mapa<<std::endl;
	//std::cout<<"Map: "<<&Map<<std::endl;
	//Game::Mapa = new Game::Map();
	//Player = new GameObject("imagesPlaceHolder/IdlePlayer.png", 0, 0);
	//std::cout<<"Map initialize"<<std::endl;
	Game::Map.addComponent<TransformComponent>(0.0f,0.0f,false);
	//std::cout<<"Map initialize"<<std::endl;
	Game::Map.addComponent<SpriteComponent>("../images/BGZombieCC.png",3000,480);
	//std::cout<<"Map initialize"<<std::endl;
	Game::Map.addComponent<KeyBoardController>();
	//std::cout<<"Map initialize"<<std::endl;
	Player.addComponent<TransformComponent>(180.0f,200.0f,false);
	Player.addComponent<SpriteComponent>("../images/Main-Character-x256.png",256,256);
	Player.setPlayer(true);
	//Player.addComponent<KeyBoardController>();

	zombieManager = new ZombieManager();
	/*
	//Test
	Enemy.addComponent<TransformComponent>(200.0f,200.0f);
	Enemy.addComponent<SpriteComponent>("imagesPlaceHolder/AnotherPlayer.png");
	Enemy.addComponent<KeyBoardController>();
	Enemy.SetZombie(true);

	Ally.addComponent<TransformComponent>(600.0f,200.0f);
	Ally.addComponent<SpriteComponent>("imagesPlaceHolder/IdlePlayer.png");
	Ally.addComponent<KeyBoardController>();
	Ally.SetZombie(true);*/
}

void Game::handleEvents()
{

	SDL_PollEvent(&e);
	switch(e.type)
	{
		case SDL_QUIT:
			running=false;
			break;
		default:
			break;
	}

}

void Game::update()
{
	Game::manager.refresh();
	Game::manager.update();
	zombieManager->update();
/*Game::Mapa->dest.x =Player.getComponent<TransformComponent>().position.x *-4;
	if(Game::Mapa->dest.x>0){
		Game::Mapa->dest.x =0;
		Player.getComponent<TransformComponent>().position.x=0;
	}
	if(Game::Mapa->dest.x<3000*-1+800){
		Game::Mapa->dest.x = 3000*-1+800;
		Player.getComponent<TransformComponent>().position.x=550;
	}*/

}

void Game::render()
{
	SDL_RenderClear(renderer);
	//SDL_RenderCopy(renderer, backgroundTex,NULL,NULL);
	//Game::Mapa->DrawGame::Map();
	Game::manager.draw();

	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);

	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout<<"Game clean"<<std::endl;
}
