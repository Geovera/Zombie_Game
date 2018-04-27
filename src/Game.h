/*
 * Game.h
 *
 *  Created on: Apr 24, 2018
 *      Author: eliro
 */

#ifndef GAME_H_
#define GAME_H_

#include <SDL2/SDL.h>
#include "Player.h"

class Game {
public:
	Game();
	virtual ~Game();

	void init(const char* title, int xpos, int ypos,int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool isRunning(){return running;}



private:

	bool running;
	int cnt;
	Player* survivor;
	SDL_Window* window;
	SDL_Texture* backgroundTex;
	SDL_Renderer* renderer;
};

#endif /* GAME_H_ */
