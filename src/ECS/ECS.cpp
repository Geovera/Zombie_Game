#include "ECS.h"
//#include "../leaker.h"


void Entity::addGroup(Group mGroup){
  groupBitSet[mGroup]=true;
  //std::cerr<<"Man: "<<manager<<std::endl;
  //std::cerr<<"Play: "<<this<<std::endl;
  manager->addToGroup(this,mGroup);
}
