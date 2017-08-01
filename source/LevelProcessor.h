#ifndef _LevelProcessor_
#define _LevelProcessor_

#include "GameMap.h"
#include "struct/Color.cpp"
#include "vector"

class LevelProcessor
{
  public:
    std::vector<struct Point> getExpandPoints(GameMap gameMap, enum Color color);
    
};

#endif