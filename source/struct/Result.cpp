#ifndef _Result_
#define _Result_

#include "Point.cpp"
#include "../Config.h"
#include "vector"
#include <stdlib.h>

#define random(x) (rand() % x)

class Result
{
  public:
    void add(struct Point point, int value)
    {
        if (value > maxValue)
        {
            maxValue = value;
            pointList.clear();
        }
        pointList.push_back(point);
        *this->point = pointList[random(pointList.size())];
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