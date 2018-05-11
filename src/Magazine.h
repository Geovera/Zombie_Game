#ifndef MAGAZINE_H
#define MAGAZINE_H

#include<vector>
#include<SDL2/SDL.h>
#include"ECS/Components.h"

class magazineComponent: public Component
{
public:

  Magazine()
  {
  Clip();
  }
  void Clip(){
    for(int i = 0; i <30; i++)
    {
    Entity& Bullet(Game::manager.addEntity());
    Entity* AnotherBullet = &Bullet;
    Magazine.push_back(AnotherBullet);
    Magazine[i]->SetZombie(true);
    }
  }
  void Shots()
  {
    int posX = Game::Map.getComponent<TransformComponent>().position.x;
    //std::cout<<"X: "<<posX<<std::endl;
    //std::cout<<"X1: "<<posX + 1500<<std::endl;
    if(timePassed<zombieDelay)
      return;
    if(currentIndex%2==0){
      zombies[currentIndex]->addComponent<TransformComponent>(posX,200.0f,false);
      zombies[currentIndex]->addComponent<SpriteComponent>("../images/Zombie-Test.png",256,256);
      zombies[currentIndex]->addComponent<KeyBoardController>();
    }
    else{
      zombies[currentIndex]->addComponent<TransformComponent>(posX+1500.0f,200.0f,true);
      zombies[currentIndex]->addComponent<SpriteComponent>("../images/Zombie-Test.png",256,256,SDL_FLIP_HORIZONTAL);
      zombies[currentIndex]->addComponent<KeyBoardController>();
    }
    currentIndex++;
    timePassed=0.0f;
  }
  void bulletUpdate()
  {
    float
  }


private:

  std::vector<Entity*> Magazine;








};




#endif //MAGAZINE_H
