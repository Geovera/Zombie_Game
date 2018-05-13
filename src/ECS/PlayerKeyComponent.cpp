#include "PlayerKeyComponent.h"

void PlayerKeyComponent::ShotBullets()
{
  entity->getComponent<MagazineComponent>()->Shots();
}

void PlayerKeyComponent::Flip(SDL_RendererFlip asd)
{
  entity->getComponent<SpriteComponent>()->flipType=asd;
}
void PlayerKeyComponent::MagClip()
{
  entity->getComponent<MagazineComponent>()->Clip();
}
