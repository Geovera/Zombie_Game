/*
 * Game.cpp
 *
 *  Created on: Apr 24, 2018
 *      Author: eliro
 */

#include "Game.h"
#include "Player.h"
#include "textureManager.h"
#include <iostream>



Game::Game() {
	// TODO Auto-generated constructor stub
	window = NULL;
	renderer = NULL;
	backgroundTex = NULL;
	survivor = new Player;
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
	backgroundTex = textureManager::loadTexture("src/imagesPlaceHolder/background.bmp", renderer);
	survivor->playerTexture=textureManager::loadTexture(survivor->getImagePath(), renderer);
}

void Game::handleEvents()
{
	SDL_Event e;
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

}

void Game::render()
{
	cnt++;
	survivor->setXpos(cnt);
	SDL_RenderClear(renderer);
	SDL_Rect tmpRect = survivor->getDestRect();
	SDL_RenderCopy(renderer, backgroundTex,NULL,NULL);
	SDL_RenderCopy(renderer, survivor->playerTexture,NULL,&tmpRect);

	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);

	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout<<"Game clean"<<std::endl;
}

