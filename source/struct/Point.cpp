#ifndef _POINT_
#define _POINT_
struct Point
{
    int x, y;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Point() {}
};
#endif