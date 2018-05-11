#include<"PlayerKeyComponent.h">

 void PlayerKeyComponent::ShotBullet()
 {
   entity->getComponent<MagazineComponent>()->Shots();
 }
