/*
 * GameObject.h
 *
 *  Created on: Apr 26, 2018
 *      Author: eliro
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <SDL2/SDL.h>

class GameObject {
public:
	GameObject(const char* textureSheet, SDL_Renderer* ren);
	virtual ~GameObject();

	void Update();
	void Render();

private:

	int xPos;
	int yPos;

	SDL_Texture* objTexture;
	SDL_Renderer* renderer;
	SDL_Rect srcRect, dstRect;


};

#endif /* GAMEOBJECT_H_ */
