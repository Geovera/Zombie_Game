
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
    zombiesNumber =5;
    zombies.clear();
    for(int i=0;i<zombiesNumber;i++)
    {
      Entity& tempZombie(Game::manager.addEntity());
      Entity* AnotherZombie = &tempZombie;
      zombies.push_back(AnotherZombie);
      zombies[i]->SetZombie(true);
    }
    roundOver=false;
  }
  void spawnZombie()
  {
    if(timePassed<zombieDelay)
      return;
    zombies[currentIndex]->addComponent<TransformComponent>(Game::Map->getComponent<TransformComponent>().position.x,200.0f);
    zombies[currentIndex]->addComponent<SpriteComponent>("imagesPlaceHolder/AnotherPlayer.png");
    zombies[currentIndex]->addComponent<KeyBoardController>();
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
