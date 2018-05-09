

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

  virtual ~Component(){}

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
    //T* c(new T(std::forward<Targs>(mArgs)...));
    T* c=new T(std::forward<Targs>(mArgs)...);
    //std::cout<<"1: "<<c<<std::endl;
    c->entity =this;
    //std::cout<<"2: "<<c<<std::endl;
    //Component* uPtr{c};
    components.push_back(c);
    //std::cout<<"3: "<<c<<std::endl;

    //long ID = (long)getComponentTypeID<T>();
    //std::cout<<"Test2: "<<ID<<std::endl;
    componentArray[getComponentTypeID<T>()] = c;
    //std::cout<<"Test: "<<std::endl;
    componentBitSet[getComponentTypeID<T>()] =true;
    //std::cout<<"X: "<<componentArray[ID]<T>.x()<<std::endl;
    //std::cout<<"4: "<<c<<std::endl;
    c->init();
    //std::cout<<"5: "<<c<<std::endl;
    //return *c;
  }

  template <class T> T& getComponent() const
  {

    auto ptr(componentArray[getComponentTypeID<T>()]);
    return *static_cast<T*>(ptr);
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
