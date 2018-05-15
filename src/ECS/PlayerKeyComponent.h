

#ifndef PLAYERKEYCOMPONENT_H_
#define PLAYERKEYCOMPONENT_H_

#include "Components.h"

class PlayerKeyComponent : public Component
{
public:
  bool selfState = true;

  void init() override
  {
    selfState = true;
  }
  void ShotBullets();
  void MagClip();
  void Flip(SDL_RendererFlip asd);

  void update() override
  {
    if(Game::e.type ==SDL_KEYDOWN)
    {
      switch(Game::e.key.keysym.sym)
      {
        case SDLK_LEFT:
          Flip(SDL_FLIP_HORIZONTAL);
          selfState = false;
          break;
        case SDLK_RIGHT:
          Flip(SDL_FLIP_NONE);
          selfState = true;
          break;
        case SDLK_SPACE:
          ShotBullets();
          break;
        case SDLK_r:
          MagClip();
          std::cerr<<"SHot"<<std::endl;
          break;
        default:
          break;
      }
    }
  }
};

#endif //PLAYERKEYCOMPONENT_H_
