//============================================================================
// Name        : videoGameProject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"
using namespace std;

const int width = 640;
const int height = 480;

Game* zombie=NULL;

int main() {

	zombie = new Game;

	zombie->init("Zombie Massacre", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, width, height,false);

	while(zombie->isRunning())
	{
		zombie->handleEvents();
		zombie->update();
		zombie->render();
	}

	zombie->clean();
	return 0;
}
