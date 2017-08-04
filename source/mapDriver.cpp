#include "mapDriver.h"
#include "Config.h"

static const int BUFFER_SIZE = 32;

enum Color **readMap()
{
    freopen("data/gameData.txt", "r", stdin);
    //初始化
    enum Color **map = new enum Color *[Config::size];
    for (int i = 0; i < Config::size; i++)
        map[i] = new enum Color[Config::size];

    char *buffer = new char[BUFFER_SIZE];
    for (int i = 0; i < Config::size; i++)
    {
        scanf("%s", buffer);
        for (int j = 0; j < Config::size; j++)
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
    delete[] buffer;
    return map;
}

void writeMap(enum Color **map)
{
    freopen("data/gameData.txt", "w", stdout);
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
}
