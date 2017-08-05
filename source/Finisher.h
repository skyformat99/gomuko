#ifndef _Finisher_
#define _Finisher_

#include "Analyzer.h"
#include "struct/Color.cpp"
#include "struct/Point.cpp"
#include "GameMap.h"
#include "Score.h"
#include "logger.h"

class Finisher
{
  public:
    static bool canKill(GameMap *gameMap, enum Color targetColor, int deep, Score *score);

  private:
    static bool dfsKill(GameMap *gameMap, enum Color color, enum Color targetColor, int level, Score *score,struct Point *lastPoint);

    static vector<struct Point> getComboAttackPoints(GameMap *gameMap, Color color, Analyzer *data);

    static vector<struct Point> getComboDefencePoints(GameMap *gameMap, Color color, Analyzer *data);

    static void setColor(Point point, Color color, Color forwardColor, Color aiColor, Score *score, GameMap *gameMap);
    
    static vector<struct Point> converToVector(set<struct Point> *points);

    static vector<struct Point> converToVector(set<struct Point> *points1, set<struct Point> *points2);
};

#endif