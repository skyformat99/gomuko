#include "Score.h"
#include "mapDriver.h"
#include "struct/Color.cpp"
#include <stdio.h>
#include "logger.h"

int main()
{
    enum Color **map = readMap();
    printMapToConsole(map);
    Score score;
    score.initScore(map, BLACK);
    printf("value = %d\n", score.getMapScore());
    return 0;
}