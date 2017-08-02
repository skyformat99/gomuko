#include "logger.h"
#include "time.h"

unsigned long currentTime = clock();

void printMapToConsole(enum Color **map)
{
    for (int i = 0; i < Config::size; i++)
    {
        for (int j = 0; j < Config::size; j++)
        {
            enum Color value = map[i][j];
            if (value == BLACK)
                printf("x");
            if (value == WHITE)
                printf("o");
            if (value == VOID)
                printf(".");
        }
        printf("\n");
    }
    printf("\n");
}

void printSelectPoint(struct Point point, int value, Counter counter)
{
    int second = (clock() - currentTime)/(CLOCKS_PER_SEC/1000);
    printf("point %d %d value = %d count = %d time = %d ms \n", point.x, point.y, value, counter.count, second);
}