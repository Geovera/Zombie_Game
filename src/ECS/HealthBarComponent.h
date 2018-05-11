/*
 * HealthBarComponent.h
 *
 *  Created on: May 9, 2018
 *      Author: Evan Blake
 */

#ifndef HEALTHBARCOMPONENT_H_
#define HEALTHBARCOMPONENT_H_

#include "Components.h"
#include "TransformComponent.h"
#include <SDL2/SDL.h>


class HealthBarComponent : public Component
{
public:
	//TransformComponent* transformHealth;
	SDL_Rect m_rect;

	HealthBarComponent()
	{
		SDL_Rect rect;
		rect.x=10;
		rect.y=10;
		rect.w=200;
		rect.h=50;
		m_rect = rect;
		SDL_SetRenderDrawColor(Game::renderer,255,0,0,0);
		std::cout<<"DrawColor good"<<std::endl;
		SDL_RenderFillRect(Game::renderer,&rect);
		std::cout<<"FllRect good"<<std::endl;
		SDL_RenderPresent(Game::renderer);
		std::cout<<"RenderPresent good"<<std::endl;

	}

	SDL_Color color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
	{
	   SDL_Color col = {r,g,b,a};
	   return col;
	}

	HealthBarComponent(int x, int y, int w, int h,float Percent, SDL_Color FGColor, SDL_Color BGColor)
	{
		Percent = Percent > 1.f ? 1.f : Percent < 0.f ? 0.f : Percent;
		   SDL_Color old;
		   SDL_GetRenderDrawColor(Game::renderer, &old.r, &old.g, &old.g, &old.a);
		   SDL_Rect bgrect = { x, y, w, h };
		   SDL_SetRenderDrawColor(Game::renderer, BGColor.r, BGColor.g, BGColor.b, BGColor.a);
		   SDL_RenderFillRect(Game::renderer, &bgrect);
		   SDL_SetRenderDrawColor(Game::renderer, FGColor.r, FGColor.g, FGColor.b, FGColor.a);
		   int pw = (int)((float)w * Percent);
		   int px = x + (w - pw);
		   SDL_Rect fgrect = { px, y, pw, h };
		   SDL_RenderFillRect(Game::renderer, &fgrect);
		   SDL_SetRenderDrawColor(Game::renderer, old.r, old.g, old.b, old.a);
		  // SDL_RenderPresent(Game::renderer);
	}



	/*void init() override
	{
		transformHealth = &entity->getComponent<TransformComponent>();
		std::cout<<"good init"<<std::endl;
	}*/

	//if collision then change shape of rect to -25%
	 void renderBar()
	 {
		HealthBarComponent(10,10,100,50, 1.0f,color(0,255,0,255), color(0,255,0,255) );
		//SDL_RenderPresent(Game::renderer);
		//SDL_SetRenderDrawColor(Game::renderer,255,0,0,0);
		std::cout<<"DrawColor good : "<<std::endl;
		//SDL_RenderFillRect(Game::renderer,&m_rect);
	 }



};



#endif /* SRC_ECS_HEALTHBARCOMPONENT_H_ */
