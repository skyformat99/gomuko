#ifndef _Game_
#define _Game_

#include "GameMap.h"
#include "struct/Counter.cpp"
#include "struct/Result.cpp"
#include "struct/Color.cpp"
#include "struct/Point.cpp"
#include "LevelProcessor.h"
#include "Score.h"
#include "logger.h"
#include "Analyzer.h"

using namespace std;

class Game
{
  public:
    void init(enum Color **map, Config config);

    Result *search(enum Color color);

  private:
    GameMap gameMap;

    Counter counter;

    Result result;

    Config config;

    LevelProcessor levelProcessor;

    Color aiColor;

    Score score;

    int dfsScore(int level, enum Color color, int parentMin, int parentMax);

    void setColor(struct Point point, enum Color color, enum Color forwardColor, enum Color aiColor);

    int getScore();
};

#endif
