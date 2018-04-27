/*
 * textureMagager.h
 *
 *  Created on: Apr 26, 2018
 *      Author: eliro
 */


#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_
#include <SDL2/SDL.h>

class textureManager {
public:

	static SDL_Texture* loadTexture(const char* path, SDL_Renderer* renderer);

};


SDL_Texture* textureManager::loadTexture(const char* path, SDL_Renderer* renderer)
{

	SDL_Surface* tmpSurface = SDL_LoadBMP(path);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return tex;
}

#endif /* TEXTUREMAGAGER_H_ */
