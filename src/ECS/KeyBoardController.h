
#include "../Game.h"
#include "Components.h"
#include "TransformComponent.h"
//#include "../leaker.h"


#ifndef KEYBOARDCONTROLLER_H_
#define KEYBOARDCONTROLLER_H_

class KeyBoardController : public Component
{
public:
  TransformComponent* transform;

  void init() override
  {
    transform= entity->getComponent<TransformComponent>();
  }

  void update() override
  {
    if(Game::e.type ==SDL_KEYDOWN)
    {
      switch(Game::e.key.keysym.sym)
      {
        case SDLK_LEFT:
          transform->velocity.x=1;
          break;
        case SDLK_RIGHT:
          transform->velocity.x=-1;
          break;
        default:
          break;
      }
    }
    if(Game::e.type==SDL_KEYUP)
    {
      switch(Game::e.key.keysym.sym)
      {
        case SDLK_LEFT:
          transform->velocity.x=0;
          break;
        case SDLK_RIGHT:
          transform->velocity.x=0;
          break;
        default:
          break;
      }
    }
  }
};

#endif //KEYBOARDCONTROLLER_H_
