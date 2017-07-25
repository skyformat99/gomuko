#include "struct/Point.c"

int directX[] = {0, 1, 1, 1, 0, -1, -1, -1};
int directY[] = {1, 1, 0, -1, -1, -1, 0, 1};

const int BOARD_SIZE = 15;

bool reachable(struct Point point)
{
    if (point.x < 0 || point.x >= BOARD_SIZE)
        return false;
    if (point.y < 0 || point.y >= BOARD_SIZE)
        return false;
    return true;
}

