#ifndef MAGAZINE_H
#define MAGAZINE_H

#include<vector>
#include<SDL2/SDL.h>
#include"ECS/Components.h"

class MagazineComponent: public Component
{
public:

  MagazineComponent()
  {
    shootDelay = 1.0;
    timePassed = 0.0;
    currentIndex = 0;
  Clip();
  }

  void Clip(){
    for(int i = 0; i <30; i++)
    {
    Entity& Bullet(Game::manager.addEntity());
    Entity* AnotherBullet = &Bullet;
    Magazine.push_back(AnotherBullet);
    Magazine[i]->addGroup(groupBullets);
    }
  }
  void Shots()
  {
    int posX = entity->getComponent<TransformComponent>()->position.x;

    if(timePassed<shootDelay)
      return;
    if(entity->getComponent<PlayerKeyComponent>()->selfState==false){
      Magazine[currentIndex]->addComponent<TransformComponent>(posX,200.0f,5);
      Magazine[currentIndex]->addComponent<SpriteComponent>("../images/Zombie-Test.png");
      Magazine[currentIndex]->addComponent<KeyBoardController>();
    }
    else{
      Magazine[currentIndex]->addComponent<TransformComponent>(posX,200.0f,-5);
      Magazine[currentIndex]->addComponent<SpriteComponent>("../images/Zombie-Test.png",SDL_FLIP_HORIZONTAL);
      Magazine[currentIndex]->addComponent<KeyBoardController>();
    }
    currentIndex++;
    timePassed=0.0f;
  }
  void update() override{
    timePassed += 0.01;

  }


private:
  double shootDelay;
  double timePassed;
  unsigned int currentIndex;
  std::vector<Entity*> Magazine;








};




#endif //MAGAZINE_H
