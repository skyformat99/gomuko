#include "gameMap.h"

static int directX[] = {0, 1, 1, 1, 0, -1, -1, -1};
static int directY[] = {1, 1, 0, -1, -1, -1, 0, 1};

static const int BOARD_SIZE = 15;

int reachable(struct Point point)
{
    if (point.x < 0 || point.x >= BOARD_SIZE)
        return 0;
    if (point.y < 0 || point.y >= BOARD_SIZE)
        return 0;
    return 1;
}

