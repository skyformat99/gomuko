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

    bool operator<(const struct Point &right) const //重载<运算符
    {
        if (this->x == right.x && this->y == right.y) //根据id去重
            return false;
        else
        {
            if (this->x != right.x)
            {
                return this->x > right.x;
            }
            else
            {
                return this->y > right.y;
            }
        }
    }
};
#endif