#ifndef _Analyzer_
#define _Analyzer_

#include "set"
#include "struct/Color.cpp"
#include "struct/Point.cpp"
#include "GameMap.h"
#include "Score.h"

using namespace std;

class Analyzer
{
  public:
    Analyzer(GameMap gameMap, Color color, vector<struct Point> points, Score score);

    set<struct Point> fiveAttack;

    set<struct Point> fourAttack;

    set<struct Point> threeOpenAttack;

    set<struct Point> fourDefence;

    set<struct Point> threeDefence;

    set<struct Point> twoAttack;

    set<struct Point> fullPoints;

  private:
    const static int SIZE = 128;

    const static int directX[4];
    const static int directY[4];
};

#endif