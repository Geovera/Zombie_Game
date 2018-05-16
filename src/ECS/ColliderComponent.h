

#ifndef COLLIDERCOMPONENT_H_
#define COLLIDERCOMPONENT_H_

//#include "../leaker.h"

#include "../Game.h"
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

  ColliderComponent(std::string t)
  {
    tag = t;
  }
  virtual ~ColliderComponent()
  {
    std::cerr<<"Collider destroy"<<std::endl;
  }

  void init() override
  {
    if(!entity->hasComponent<TransformComponent>())
      entity->addComponent<TransformComponent>();
    transform = entity->getComponent<TransformComponent>();

  }
  void update() override
  {
    collider.x = (int)transform->position.x;
    collider.y = (int)transform->position.y;
    collider.w = transform->width * transform->scale -180;
    collider.h = transform->height * transform->scale;

    Game::colliders.push_back(this);
  }

};

#endif //COLLIDERCOMPONENT_H_
