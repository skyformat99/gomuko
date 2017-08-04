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
    vector<struct Point> getExpandPoints(Analyzer *data);
    
  private:
    vector<struct Point> selectSet(Analyzer *data);

    vector<struct Point> converToVector(set<struct Point> *points);

    vector<struct Point> converToVector(set<struct Point> *points1, set<struct Point> *points2);

    vector<struct Point> converToVector(set<struct Point> *points1, set<struct Point> *points2, set<struct Point> *points3, set<struct Point> *points4);

    vector<struct Point> removeRepeat(vector<struct Point> *points);
};

#endif