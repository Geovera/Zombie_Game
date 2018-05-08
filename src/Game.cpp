/*
 * Game.cpp
 *
 *  Created on: Apr 24, 2018
 *      Author: eliro
 */

#include "Game.h"
#include "textureManager.h"
#include "ECS/Components.h"
//#include "ECS/KeyBoardController.h"
#include "Vector2D.h"
#include <iostream>


SDL_Event Game::e;
SDL_Renderer* Game::renderer =NULL;


Manager manager;
auto& Map(manager.addEntity());
auto& Player(manager.addEntity());
auto& Enemy(manager.addEntity());
auto& Ally(manager.addEntity());

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
	SCREEN_WITDH = width;
	SCREEN_HEIGHT = height;
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
	mapa = new Map();
	//Player = new GameObject("imagesPlaceHolder/IdlePlayer.png", 0, 0);

	Map.addComponent<TransformComponent>(0.0f,0.0f);
	Map.addComponent<SpriteComponent>("../");

	Player.addComponent<TransformComponent>(200.0f,200.0f);
	Player.addComponent<SpriteComponent>("../images/Main-Character64x64.png");
	//Player.addComponent<KeyBoardController>();

	//Test
	Enemy.addComponent<TransformComponent>(200.0f,200.0f);
	Enemy.addComponent<SpriteComponent>("imagesPlaceHolder/AnotherPlayer.png");

	Ally.addComponent<TransformComponent>(600.0f,200.0f);
	Ally.addComponent<SpriteComponent>("imagesPlaceHolder/IdlePlayer.png");
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
	manager.refresh();
	manager.update();

	mapa->dest.x =Player.getComponent<TransformComponent>().position.x *-4;
	if(mapa->dest.x>0){
		mapa->dest.x =0;
		Player.getComponent<TransformComponent>().position.x=0;
	}
	if(mapa->dest.x<3000*-1+800){
		mapa->dest.x = 3000*-1+800;
		Player.getComponent<TransformComponent>().position.x=550;
	}

}

void Game::render()
{
	SDL_RenderClear(renderer);
	//SDL_RenderCopy(renderer, backgroundTex,NULL,NULL);
	mapa->DrawMap();
	manager.draw();

	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);

	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout<<"Game clean"<<std::endl;
}
