/*
 * Player.h
 *
 *  Created on: Apr 24, 2018
 *      Author: eliro
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <SDL2/SDL.h>

class Player {
public:
	Player(char* path = "src/imagesPlaceHolder/IdlePlayer.bmp");
	virtual ~Player();

	char* getImagePath(){return imagePath;}
	SDL_Rect getSrcRect(){return srcR;}
	SDL_Rect getDestRect(){return destR;}
	SDL_Texture* playerTexture;

private:
	char* imagePath;
	SDL_Rect srcR, destR;
};

#endif /* PLAYER_H_ */
