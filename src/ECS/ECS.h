

#ifndef ECS_H_
#define ECS_H_

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID()
{
  static ComponentID lastTypeID =0;
  return lastTypeID++;
}

template <class T> inline ComponentID getComponentTypeID() noexcept
{
  static ComponentID typeID = getComponentTypeID();
  return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component* ,maxComponents>;

class Component
{
public:
  Entity* entity;

  int ID;

  virtual void init() {}
  virtual void update(){}
  virtual void draw() {}

  virtual ~Component(){
    std::cerr<<"Component object is destroy"<<std::endl;
  }

};

class Entity
{
private:
  bool active = true;
  int currentIndex=0;
  std::vector<Component*> components;

  ComponentArray componentArray;
  ComponentBitSet componentBitSet;

public:
  void update()
  {
    for(auto& c: components) c->update();
  }
  void draw(){
    for(auto& c: components) c->draw();
  }

  bool zombie=false;
  bool player=false;
  void SetZombie(bool set){zombie=set;}
  void setPlayer(bool set){player=set;}
  bool isActive(){return active;}
  void destroy(){active = false;}

  template <class T> bool hasComponent() const
  {
    //long ID = (long)getComponentTypeID<T>-4206580;
    return componentBitSet[getComponentTypeID<T>()];
  }

  template <class T, class... Targs>
  void addComponent(Targs&&... mArgs)
  {
    T* c = new T(Targs(mArgs)...);
    c-> entity = this;
    components.push_back(c);
    componentArray[getComponentTypeID<T>()]=c;
    componentBitSet[getComponentTypeID<T>()]=true;
    c->init();
  }

  template <class T> T* getComponent() const
  {
    //std::cerr<<"AdTrans: "<<componentArray[getComponentTypeID<T>()]<<std::endl;
    return static_cast<T*>(componentArray[getComponentTypeID<T>()]);
  }


};

class Manager
{
private:
  //std::vector<std::unique_ptr<Entity>> entities;
  std::vector<Entity*> entities;
public:
  void update()
  {
    for(auto& e: entities ) e->update();
  }
  void draw()
  {
    for(auto& e: entities) e->draw();
  }

  void refresh()
  {
    entities.erase(std::remove_if(std::begin(entities),std::end(entities),
      [](Entity* mEntity)
    {
      return !mEntity ->isActive();
    }),
      std::end(entities));
  }

  Entity& addEntity()
  {
    Entity* e = new Entity();
    //std::unique_ptr<Entity> uPtr{e};
    //entities.emplace_back(std::move(uPtr));
    entities.push_back(e);
    return *e;
  }

};




#endif //ECS_H_
