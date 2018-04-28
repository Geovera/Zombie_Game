

#ifndef TRANSFROMCOMPONENT_H_
#define TRANSFROMCOMPONENT_H_

#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component
{

public:
  Vector2D position;

  Vector2D velocity;

  int speed =3;
  TransformComponent()
  {
    position.x =0.0f;
    position.y=0.0f;
  }

  TransformComponent(float x, float y)
  {
    position.x = x;
    position.y =y;
  }

  virtual ~TransformComponent(){}

  void init() override
  {
    velocity.x =0;
    velocity.y =0;
  }
  void update() override
  {
    position.x+= velocity.x * speed;
  }

};

#endif //TRANSFORMCOMPONENT_H_
