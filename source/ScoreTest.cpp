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
    score.initScore(map, WHITE);
    int ***count = score.getColorCount(WHITE);
    for (int i = 0; i < Config::size; i++)
        for (int j = 0; j < Config::size; j++)
            for (int k = 0; k < 4; k++)
            {
                if (count[i][j][k] >= 2)
                    printf("count %d %d %d = %d\n", i, j, k, count[i][j][k]);
            }
    printf("value = %d\n", score.getMapScore());
    return 0;
}