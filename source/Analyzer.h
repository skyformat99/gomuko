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
    void init(GameMap *gameMap, Score* score);

    void buildSet(enum Color color, vector<struct Point>* points);

    void reset(GameMap *gameMap, Color color, vector<struct Point>* points, Score* score);
    
    void changePoint(struct Point point);

    bool fiveAttackSignal[2][Config::size][Config::size][4];
    
    bool fourAttackSignal[2][Config::size][Config::size][4];

    bool fourDefenceSignal[2][Config::size][Config::size][4];

    bool threeAttackSignal[2][Config::size][Config::size][4];

    bool threeDefenceSignal[2][Config::size][Config::size][4];

    bool twoAttackSignal[2][Config::size][Config::size][4];

    set<struct Point> fiveAttack;

    set<struct Point> fourAttack;

    set<struct Point> threeOpenAttack;

    set<struct Point> fourDefence;

    set<struct Point> threeDefence;

    set<struct Point> twoAttack;

    set<struct Point> fullPoints;

  private:

    void update(struct Point point, enum Color color, int direct);

    const static int SIZE = 128;

    const static int directX[4];
    const static int directY[4];

    Score *score;
    GameMap *gameMap;
};

#endif