#ifndef _LevelProcessor_
#define _LevelProcessor_

#include "GameMap.h"
#include "struct/Color.cpp"
#include "vector"
#include "set"
#include "Analyzer.h"

using namespace std;

class LevelProcessor
{
  public:
    vector<struct Point> *getExpandPoints(Analyzer *data);

    vector<struct Point> *getExpandPoints(GameMap *gameMap,enum Color color);

  private:
    void selectSet(Analyzer *data);

    void converToVector(set<struct Point> *points, vector<struct Point> *target);

    void removeRepeat();

    vector<struct Point> result;

    vector<struct Point> finalResult;

    set<struct Point> hash;

    vector<struct Point> pointFullPoints;

    vector<struct Point> pointFourAttack;

    vector<struct Point> pointThreeOpenAttack;

    vector<struct Point> pointThreeDefence;

    vector<struct Point> pointTwoAttack;
};

#endif