#ifndef _WinChecker_
#define _WinChecker_

#include "struct/Color.cpp"
#include "Config.h"
#include "GameMap.h"

class WinChecker
{
  public:
    static enum Color win(GameMap gameMap);
};

#endif