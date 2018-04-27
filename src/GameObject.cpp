/*
 * GameObject.cpp
 *
 *  Created on: Apr 26, 2018
 *      Author: eliro
 */

#include "GameObject.h"
#include "textureManager.h"
//#include <SDL2/SDL.h>

GameObject::GameObject(const char* textureSheet, SDL_Renderer* ren) {
	// TODO Auto-generated constructor stub
	renderer = ren;
	objTexture = textureManager::loadTexture(textureSheet, ren);


}

GameObject::~GameObject() {
	// TODO Auto-generated destructor stub
}

void GameObject::Update()
{

}

void GameObject::Render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &dstRect);
}

