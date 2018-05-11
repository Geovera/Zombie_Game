

#ifndef PLAYERKEYCOMPONENT_H_
#define PLAYERKEYCOMPONENT_H_

#include "Components.h"

class PLAYERKEYCOMPONENT_H_ : public Component
{
public:
  bool selfState = true;

  void init() override
  {
    selfState = true;
  }

  void update() override
  {
    if(Game::e.type ==SDL_KEYDOWN)
    {
      switch(Game::e.key.keysym.sym)
      {
        case SDLK_LEFT:
          selfState = true;
          break;
        case SDLK_RIGHT:
          selfState = false;
          break;
        default:
          break;
      }
    }
  }
};

#endif //PLAYERKEYCOMPONENT_H_