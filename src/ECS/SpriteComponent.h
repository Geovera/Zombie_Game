
#include <SDL2/SDL.h>

#ifndef SPRITECOMPONENT_H_
#define SPRITECOMPONENT_H_
#include "Components.h"
#include "TransformComponent.h"


class SpriteComponent : public Component
{

private:
  TransformComponent* transform;
  SDL_Rect srcRect, destRect;
  SDL_Texture* texture;
public:
  SpriteComponent() =default;
  SpriteComponent(const char* path, int width=64, int height=64){
    setTex(path);
    srcRect.x = srcRect.y =0;
    srcRect.w = width;
    srcRect.h =height;
    destRect.w = width;
    destRect.h = height;
  }
  virtual ~SpriteComponent(){}

  void setTex(const char* path)
  {
    texture =textureManager::loadTexture(path);
  }

  void init() override
  {
    transform = &entity->getComponent<TransformComponent>();


  }
  void update() override
  {
    destRect.x = (int)transform->position.x;
    destRect.y = (int)transform->position.y;
  }

  void draw() override
  {
    textureManager::Draw(texture,srcRect,destRect);
  }

};



#endif //SPRITECOMPONENT_H_
