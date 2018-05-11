
#ifndef ZOMBIEMANAGER_H_
#define ZOMBIEMANAGER_H_

#include <vector>
#include <stdio.h>
#include "Game.h"
#include "ECS/ECS.h"
#include <iostream>


class ZombieManager
{
public:

  ZombieManager()
  {
    zombiesNumber=0;
    round=0;
    roundOver=true;
    timePassed =0.0;
    zombieDelay = 2.0;
    currentIndex =0;
  }
  void startNewRound()
  {
    round++;
    std::cout<<"Round: "<<round<<std::endl;
    //zombiesNumber = rand() %10 +1;
    zombiesNumber =5*round;
    zombies.clear();
    for(int i=0;i<zombiesNumber;i++)
    {
      Entity& tempZombie(Game::manager.addEntity());
      Entity* AnotherZombie = &tempZombie;
      zombies.push_back(AnotherZombie);
      zombies[i]->SetZombie(true);
      //std::cout<<i<<": "<<&zombies[i]<<std::endl;
      //std::cout<<i<<" temp: "<<&tempZombie<<std::endl;
    }
    roundOver=false;
  }
  void spawnZombie()
  {

    //std::cout<<"X: "<<posX<<std::endl;
    //std::cout<<"X1: "<<posX + 3000<<std::endl;
    if(timePassed<zombieDelay)
      return;
    int posX = Game::Map.getComponent<TransformComponent>()->position.x;
    if(currentIndex%2==0){
      //std::cout<<"Hello1: "<<currentIndex<<std::endl;
      //std::cout<<"Address: "<<zombies[currentIndex]<<std::endl;
      //std::cout<<"Map: "<<&Game::Map<<std::endl;
      //std::cout<<"NO"<<std::endl;
      zombies[currentIndex]->addComponent<TransformComponent>(posX,200.0f);
      //std::cout<<"Hola1"<<std::endl;0
      //std::cerr<<"Image: "<<
      zombies[currentIndex]->addComponent<SpriteComponent>("../images/Zombie-Test.png");
      zombies[currentIndex]->addComponent<KeyBoardController>();
    }
    else{
      zombies[currentIndex]->addComponent<TransformComponent>(posX+3000.0f,200.0f,256,256, true);
      zombies[currentIndex]->addComponent<SpriteComponent>("../images/Zombie-Test.png", SDL_FLIP_HORIZONTAL);
      zombies[currentIndex]->addComponent<KeyBoardController>();
    }
    currentIndex++;
    timePassed=0.0f;
  }
  void update()
  {
    if(roundOver)
      startNewRound();
    if(currentIndex<zombiesNumber){
      timePassed+=0.01;
      spawnZombie();
    }
    //std::cout<<(begin - clock_t())/(double)CLOCKS_PER_SEC<<std::endl;

  }
/*
zombies[i].addComponent<TransformComponent>();
zombies[i].addComponent<SpriteComponent>();
zombies[i].addComponent<KeyBoardController>();*/

private:
  std::vector<Entity*> zombies;
  unsigned int zombiesNumber;
  unsigned int round;
  double timePassed;
  double zombieDelay;
  unsigned int currentIndex;
  bool roundOver;

};


#endif //ZOMBIEMANAGER_H_
