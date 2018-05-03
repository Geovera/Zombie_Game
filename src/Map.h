


#ifndef MAP_H_
#define MAP_H_

#include <SDL2/SDL.h>
#include "textureManager.h"

class Map
{
public:
  Map();
  virtual ~Map();

  //void LoadMap();
  void DrawMap();

private:

  SDL_Rect src, dest;

  SDL_Texture* background;

};




#endif //MAP_H_
