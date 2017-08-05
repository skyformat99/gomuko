#ifndef _Finisher_
#define _Finisher_

#include "Analyzer.h"
#include "struct/Color.cpp"
#include "struct/Point.cpp"
#include "struct/Counter.cpp"
#include "GameMap.h"
#include "Score.h"
#include "logger.h"

class Finisher
{
public:
  void init(GameMap *gameMap, Score *score, Counter *counter, Config *config);

  struct Point *canKill(enum Color targetColor);

private:
  GameMap *gameMap;

  Score *score;

  Counter *counter;

  Config *config;

  struct Point result;

  bool dfsKill(enum Color color, enum Color targetColor, int level, struct Point *lastPoint);

  vector<struct Point> getComboAttackPoints(enum Color color, Analyzer *data);

  vector<struct Point> getComboDefencePoints(enum Color color, Analyzer *data);

  void setColor(struct Point point, enum Color color, enum Color forwardColor, enum Color aiColor);

  static vector<struct Point> converToVector(set<struct Point> *points);

  static vector<struct Point> converToVector(set<struct Point> *points1, set<struct Point> *points2);
};

#endif