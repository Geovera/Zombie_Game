
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
    zombieDelay = 1.0;
    currentIndex =0;
    maxRound=2;
  }
  void startNewRound()
  {
    round++;
    currentIndex=0;
    std::cout<<"Round: "<<round<<std::endl;
    //zombiesNumber = rand() %10 +1;
    zombiesNumber +=round;
    zombies.clear();
    for(int i=0;i<zombiesNumber;i++)
    {
      Entity* tempZombie(Game::manager.addEntity());
      zombies.push_back(tempZombie);
      zombies[i]->addComponent<TransformComponent>(5000.0f,5000.0f);
      zombies[i]->addComponent<ColliderComponent>("zombie");
      //zombies[i]->SetZombie(true);
      zombies[i]->addGroup(groupZombies);
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
    int posX = Game::Map->getComponent<TransformComponent>().position.x;
    std::cout<<"Zombie Spawned"<<std::endl;
    if(currentIndex%2==0){
      //std::cout<<"Hello1: "<<currentIndex<<std::endl;
      //std::cout<<"Address: "<<zombies[currentIndex]<<std::endl;
      //std::cout<<"Map: "<<&Game::Map<<std::endl;
      //std::cout<<"NO"<<std::endl;
      zombies[currentIndex]->getComponent<TransformComponent>().rev=1;
      zombies[currentIndex]->getComponent<TransformComponent>().position.x=posX;
      zombies[currentIndex]->getComponent<TransformComponent>().position.y=200;

      //std::cout<<"Hola1"<<std::endl;0
      //std::cerr<<"Image: "<<
      zombies[currentIndex]->addComponent<SpriteComponent>("../images/Zombie-x256-3.png",4,200);
      zombies[currentIndex]->addComponent<KeyBoardController>();
    }
    else{
      zombies[currentIndex]->getComponent<TransformComponent>().rev=1;
      zombies[currentIndex]->getComponent<TransformComponent>().position.x=posX+1500;
      zombies[currentIndex]->getComponent<TransformComponent>().position.y=200;
      zombies[currentIndex]->addComponent<SpriteComponent>("../images/Zombie-x256-3.png", 4,200, SDL_FLIP_HORIZONTAL);
      zombies[currentIndex]->addComponent<KeyBoardController>();
    }
    currentIndex++;
    timePassed=0.0f;
  }
  void endGame()
  {
    std::cout<<"Game Over!\nYou Win!"<<std::endl;
    Game::manager.m_game->setRun(false);
  }
  void update()
  {
    if(round>maxRound)
        endGame();
    checkForZombies();
    if(roundOver)
      startNewRound();
    if(currentIndex<zombiesNumber){
      timePassed+=0.01;
      spawnZombie();
    }
    //std::cout<<(begin - clock_t())/(double)CLOCKS_PER_SEC<<std::endl;
  }
  void refresh()
  {
    zombies.erase(std::remove_if(std::begin(zombies),std::end(zombies),
      [](Entity* mEntity)
    {
      return !mEntity ->isActive();
    }),
      std::end(zombies));
  }
  void checkForZombies()
  {
    if(zombies.size()==0)
    {
      roundOver=true;
      std::cerr<<"Round Over"<<std::endl;
    }
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
  unsigned int maxRound;

};


#endif //ZOMBIEMANAGER_H_
