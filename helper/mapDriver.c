#include <stdio.h>
#include <stdlib.h>
#include "../struct/Color.c"

const int SIZE = 15;

enum Color **readMap()
{
    freopen("data/gameData.txt", "r", stdin);
    //初始化
    enum Color **map = (enum Color **)malloc(sizeof(enum Color *) * SIZE);
    for (int i = 0; i < SIZE; i++)
        map[i] = (enum Color *)malloc(sizeof(enum Color) * SIZE);

    int bufferSize = 32;
    char *buffer = (char *)malloc(sizeof(char) * bufferSize);
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%s", buffer);
        for (int j = 0; j < SIZE; j++)
        {
            char value = buffer[j];
            if (value == 'x')
                map[i][j] = BLACK;
            if (value == 'o')
                map[i][j] = WHITE;
            if (value == '.')
                map[i][j] = VOID;
        }
    }
    free(buffer);
    return map;
}

void printMapToConsole(enum Color **map)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
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