

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

  virtual void init() {}
  virtual void update(){}
  virtual void draw() {}

  virtual ~Component(){}

};

class Entity
{
private:
  bool active = true;
  std::vector<std::unique_ptr<Component>> components;

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
  void SetZombie(bool set){zombie=set;}
  bool isActive(){return active;}
  void destroy(){active = false;}

  template <class T> bool hasComponent() const
  {
    long ID = (long)getComponentTypeID<T>-4206580;
    return componentBitSet[ID];
  }

  template <class T, class... Targs>
  T& addComponent(Targs&&... mArgs)
  {
    T* c(new T(std::forward<Targs>(mArgs)...));
    c->entity =this;
    std::unique_ptr<Component> uPtr{c};
    components.emplace_back(std::move(uPtr));

    long ID = (long)getComponentTypeID<T>-4206580;
    componentArray[ID] = c;
    componentBitSet[ID] =true;
    //std::cout<<"X: "<<componentArray[ID]<T>.x()<<std::endl;

    c->init();
    return *c;
  }

  template <class T> T& getComponent() const
  {

    long ID = (long)getComponentTypeID<T>-4206580;
    auto ptr(componentArray[ID]);
    return *static_cast<T*>(ptr);
  }


};

class Manager
{
private:
  std::vector<std::unique_ptr<Entity>> entities;

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
      [](const std::unique_ptr<Entity> &mEntity)
    {
      return !mEntity ->isActive();
    }),
      std::end(entities));
  }

  Entity& addEntity()
  {
    Entity* e = new Entity();
    std::unique_ptr<Entity> uPtr{e};
    entities.emplace_back(std::move(uPtr));
    return *e;
  }

};




#endif //ECS_H_
