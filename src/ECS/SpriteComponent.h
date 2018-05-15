
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

  bool animated = false;
  int frames = 0;
  int speed = 100;

public:
  SDL_RendererFlip flipType;
  SpriteComponent() = default;
  SpriteComponent(const char* path, SDL_RendererFlip flipT= SDL_FLIP_NONE){
    //std::cerr<<"before transform: "<<entity->getComponent<TransformComponent>()<<std::endl;
    //if(!entity->hasComponent<TransformComponent>())
    //  entity->addComponent<TransformComponent>(0.0f,0.0f);
    //transform = entity->getComponent<TransformComponent>();
    //std::cerr<<"Begin: "<<path<<std::endl;
    setTex(path);


    flipType=flipT;
    std::cout<<path<<" : "<<flipType<<std::endl;
  }
  SpriteComponent(const char* path,int nFrames, int mSpeed, SDL_RendererFlip flipT= SDL_FLIP_NONE){
      //std::cerr<<"before transform: "<<entity->getComponent<TransformComponent>()<<std::endl;
      //if(!entity->hasComponent<TransformComponent>())
      //  entity->addComponent<TransformComponent>(0.0f,0.0f);
      //transform = entity->getComponent<TransformComponent>();
      //std::cerr<<"Begin: "<<path<<std::endl;
	  animated = true;
	  frames = nFrames;
	  speed = mSpeed;
      setTex(path);


      flipType=flipT;
      std::cout<<path<<" : "<<flipType<<std::endl;
    }


  virtual ~SpriteComponent(){
    SDL_DestroyTexture(texture);
  }

  void setTex(const char* path)
  {
    texture =textureManager::loadTexture(path);
  }

  void init() override
  {
    transform = entity->getComponent<TransformComponent>();
    srcRect.x = srcRect.y =0;
    //std::cerr<<"Transform w: "<<transform->width<<std::endl;
    //std::cerr<<"Begin: "<<&transform<<" : "<<path<<std::endl;

    srcRect.w = transform->width;
    //std::cerr<<"Begin: "<<path<<std::endl;
    srcRect.h =transform->height;
    //std::cerr<<"Begin: "<<path<<std::endl;
  }
  void update() override
  {
	if (animated)
	{
		srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
	}

    destRect.x = (int)transform->position.x;
    destRect.y = (int)transform->position.y;
    destRect.w = transform->width*transform->scale;
    destRect.h = transform->height*transform->scale;
  }

  void draw() override
  {
    textureManager::Draw(texture,srcRect,destRect,flipType);
  }

};



#endif //SPRITECOMPONENT_H_
