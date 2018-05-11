#include "MagazineComponent.h"

bool MagazineComponent::checkState()
{
  return (entity->getComponent<PlayerKeyComponent>()->selfState==false);
}

void MagazineComponent::Shots()
{
  int posX = entity->getComponent<TransformComponent>()->position.x;

  //if(timePassed<shootDelay)
  //  return;
  if(checkState()){
    Magazine[currentIndex]->getComponent<TransformComponent>()->position.x=posX;
    Magazine[currentIndex]->getComponent<TransformComponent>()->rev=-5;
    Magazine[currentIndex]->addComponent<SpriteComponent>("../images/Zombie-Test.png");
    Magazine[currentIndex]->addComponent<KeyBoardController>();
  }
  else{
    Magazine[currentIndex]->getComponent<TransformComponent>()->position.x=posX;
    Magazine[currentIndex]->getComponent<TransformComponent>()->rev=5;
    Magazine[currentIndex]->addComponent<SpriteComponent>("../images/Zombie-Test.png",SDL_FLIP_HORIZONTAL);
    Magazine[currentIndex]->addComponent<KeyBoardController>();
    //Magazine[currentIndex]->addComponent<ColliderComponent>("bullet");
  }
  currentIndex++;
  timePassed=0.0f;
}
