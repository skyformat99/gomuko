#ifndef _WIN_CHECKER_
#define _WIN_CHECKER_

#include "struct/Color.cpp"
#include "Config.h"
#include "GameMap.h"

class WinChecker
{
  public:
    static enum Color win(GameMap gameMap);
};

#endif