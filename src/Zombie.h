/*
 * Zombie.h
 *
 *  Created on: May 1, 2018
 *      Author: evan
 */

#ifndef SRC_ZOMBIE_H_
#define SRC_ZOMBIE_H_

#include <SDL2/SDL.h>


class Zombie {
public:
	Zombie(char* path = "src/imagesPlaceHolder/IdlePlayer.bmp");
	virtual ~Zombie();

	char* getImagePath(){return imagePath;}
	SDL_Rect getSrcRect(){return srcR;}
	SDL_Rect getDestRect(){return destR;}
	SDL_Texture* zombieTexture;

private:
	char* imagePath;
	SDL_Rect srcR, destR;
};

#endif /* SRC_ZOMBIE_H_ */
