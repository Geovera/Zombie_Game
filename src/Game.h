/*
 * Game.h
 *
 *  Created on: Apr 24, 2018
 *      Author: eliro
 */

#ifndef GAME_H_
#define GAME_H_

#include "Map.h"
#include <SDL2/SDL.h>
#include "ECS/ECS.h"
//#include <SDL2/SDL_image.h>

class Map;

class Game {
public:
	Game();
	virtual ~Game();

	void init(const char* title, int xpos, int ypos,int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	static SDL_Renderer* renderer;
	static SDL_Event e;
	static Manager manager;
	static Entity& Map;
	//static int SCREEN_WITDH;
	//static int SCREEN_HEIGHT;

	bool isRunning(){return running;}



private:

	bool running;
	int cnt;

	//Map* mapa;
	SDL_Window* window;
	SDL_Texture* backgroundTex;
};

#endif /* GAME_H_ */
