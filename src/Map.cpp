
#include "Map.h"


Map::Map()
{
  background = textureManager::loadTexture("imagesPlaceHolder/background.png");

  src.x = src.y =0;

  src.w = dest.w = 3000;
  src.h = dest.h = 640;

  dest.x = dest.y =-100;
}

Map::~Map()
{

}

void Map::DrawMap()
{
  textureManager::Draw(background,src,dest);
}
