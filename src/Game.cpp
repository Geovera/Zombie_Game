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
auto& Player(manager.addEntity());

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

	Player.addComponent<TransformComponent>(200.0f,200.0f);
	Player.addComponent<SpriteComponent>("imagesPlaceHolder/AnotherPlayer.png");
	Player.addComponent<KeyBoardController>();
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
