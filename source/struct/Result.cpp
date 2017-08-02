#ifndef _Result_
#define _Result_

#include "Point.cpp"
#include "../Config.h"
#include "vector"
#include <stdlib.h>
#include <ctime>

class Result
{
  public:
    Result(){
        srand((unsigned)time(0));
    }

    void add(struct Point point, int value)
    {
        if (value > maxValue)
        {
            maxValue = value;
            pointList.clear();
        }
        pointList.push_back(point);
        int index = rand() % pointList.size();
        this->point = &pointList[index];
    }

    void reset()
    {
        maxValue = Config::MIN_VALUE;
        point = NULL;
        pointList.clear();
    }

    struct Point *getPoint()
    {
        return point;
    }

    int getMaxValue()
    {
        return maxValue;
    }

    std::vector<struct Point> getPointList()
    {
        return pointList;
    }

  private:
    struct Point *point;

    std::vector<struct Point> pointList;

    int maxValue;
};
#endif