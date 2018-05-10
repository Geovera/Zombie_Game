

#ifndef COLLIDERCOMPONENT_H_
#define COLLIDERCOMPONENT_H_

#include "Components.h"
#include "../Vector2D.h"
#include <string>
#include <SDL2/SDL.h>

class ColliderComponent : public Component
{
public:
  SDL_Rect collider;
  std::string tag;

  TransformComponent* transform;

  void init() override
  {
    if(!entity->hasComponent<TransformComponent>())
      entity->addComponent<TransformComponent>();
    transform = &entity->getComponent<TransformComponent>();

  }

};

#endif //COLLIDERCOMPONENT_H_
