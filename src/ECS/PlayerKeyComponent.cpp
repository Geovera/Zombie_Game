<<<<<<< HEAD
#include<"PlayerKeyComponent.h">

 void PlayerKeyComponent::ShotBullet()
 {
   entity->getComponent<MagazineComponent>()->Shots();
 }
=======
#include "PlayerKeyComponent.h"

void PlayerKeyComponent::ShotBullets()
{
  entity->getComponent<MagazineComponent>()->Shots();
}

void PlayerKeyComponent::Flip(SDL_RendererFlip asd)
{
  entity->getComponent<SpriteComponent>()->flipType=asd;
}
>>>>>>> 7c6fd11219c26d7ecc0406253436a93d363cb1c3
