#ifndef _Point_
#define _Point_
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