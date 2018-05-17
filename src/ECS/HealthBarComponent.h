/*
 * HealthBarComponent.h
 *
 *  Created on: May 9, 2018
 *      Author: Evan Blake
 */

#ifndef HEALTHBARCOMPONENT_H_
#define HEALTHBARCOMPONENT_H_

#include "Components.h"
#include "../Game.h"
//#include "../leaker.h"

#include "../textureManager.h"
#include "TransformComponent.h"
#include <SDL2/SDL.h>


class HealthBarComponent : public Component
{
private:
	float health = 1.0f;
	float hitDelay = 1.0f;
	float timePassed = 0.0f;
public:
	//TransformComponent* transformHealth;
	SDL_Rect src_rect, m_rect, green_rect;
	SDL_Texture* red;
	SDL_Texture* green;

	HealthBarComponent()
	{
		SDL_Rect rect;
		rect.x=20;
		rect.y=10;
		rect.w=200;
		rect.h=50;
		m_rect = rect;
		src_rect=rect;
		green_rect=rect;
		red=textureManager::loadTexture("../images/RedBar.png");
		green=textureManager::loadTexture("../images/GreenBar.png");


	}
	virtual ~HealthBarComponent()
	{
		SDL_DestroyTexture(red);
		SDL_DestroyTexture(green);
		std::cout<<"HealthBar destroyed"<<std::endl;
	}

	void Hit(Game& game)
	{
		if(timePassed>hitDelay){
			health-=0.25f;
			green_rect.w=200*health;
			timePassed=0.0f;
			std::cerr<<"Health:"<<health*100.0f<<std::endl;
			if(health==0.0f)
				{
					std::cerr<<"Game Over!"<<std::endl;
				 game.setRun(false);
				}
		}
	}
	void update() override
	{
		timePassed+=0.01f;
	}

	SDL_Color color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
	{
	   SDL_Color col = {r,g,b,a};
	   return col;
	}





	/*void init() override
	{
		transformHealth = &entity->getComponent<TransformComponent>();
		std::cout<<"good init"<<std::endl;
	}*/

	//if collision then change shape of rect to -25%
	 void draw() override
	 {
		 textureManager::Draw(red,src_rect,m_rect, SDL_FLIP_NONE);
		 textureManager::Draw(green,src_rect,green_rect, SDL_FLIP_NONE);
		//HealthBarComponent(10,10,100,50, 1.0f,color(0,255,0,255), color(0,255,0,255) );
		//SDL_RenderPresent(Game::renderer);
		//SDL_SetRenderDrawColor(Game::renderer,255,0,0,0);
		//std::cout<<"DrawColor good : "<<std::endl;
		//SDL_RenderFillRect(Game::renderer,&m_rect);
	 }



};



#endif /* SRC_ECS_HEALTHBARCOMPONENT_H_ */
