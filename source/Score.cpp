#include "Score.h"
#include "stdio.h"

const int Score::directX[4] = {0, 1, 1, 1};
const int Score::directY[4] = {1, 1, 0, -1};

void Score::initScore(enum Color **map, enum Color aiColor)
{
    value = 0;
    for (int i = 0; i < Config::size; i++)
    {
        for (int j = 0; j < Config::size; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                blackCount[i][j][k] = 0;
                whiteCount[i][j][k] = 0;
            }
        }
    }

    for (int i = 0; i < Config::size; i++)
    {
        for (int j = 0; j < Config::size; j++)
        {
            struct Point point = Point(i, j);
            enum Color color = map[i][j];
            if (color != VOID)
            {
                setColorAndUpdate(point, color, VOID, aiColor);
            }
        }
    }
}

int Score::getMapScore()
{
    return value;
}

int Score::getValueByCount(int blackCount, int whiteCount, enum Color color)
{
    int value = 0;
    if (blackCount == 0)
    {
        if (whiteCount == 1)
            value -= ONE;
        if (whiteCount == 2)
            value -= TWO;
        if (whiteCount == 3)
            value -= THREE;
        if (whiteCount == 4)
            value -= FOUR;
    }

    if (whiteCount == 0)
    {
        if (blackCount == 1)
            value += ONE;
        if (blackCount == 2)
            value += TWO;
        if (blackCount == 3)
            value += THREE;
        if (blackCount == 4)
            value += FOUR;
    }
    if (color == WHITE)
    {
        value = -value;
    }
    return value;
}

void Score::setColorAndUpdate(struct Point point, enum Color color, enum Color forwardColor, enum Color aiColor)
{
    for (int i = 0; i < 4; i++)
    {
        int x = point.x;
        int y = point.y;
        for (int k = 0; k < 5; k++)
        {
            if (forwardColor == VOID)
            {
                value -= getValueByCount(blackCount[x][y][i], whiteCount[x][y][i], aiColor);
                if (color == BLACK)
                {
                    blackCount[x][y][i]++;
                }
                if (color == WHITE)
                {
                    whiteCount[x][y][i]++;
                }
                value += getValueByCount(blackCount[x][y][i], whiteCount[x][y][i], aiColor);
            }
            if (forwardColor != VOID)
            {
                value -= getValueByCount(blackCount[x][y][i], whiteCount[x][y][i], aiColor);
                if (color == VOID)
                {
                    if (forwardColor == BLACK)
                    {
                        blackCount[x][y][i]--;
                    }
                    if (forwardColor == WHITE)
                    {
                        whiteCount[x][y][i]--;
                    }
                }
                value += getValueByCount(blackCount[x][y][i], whiteCount[x][y][i], aiColor);
            }
            x += directX[i];
            y += directY[i];
            if (!GameMap::reachable(x, y))
            {
                break;
            }
        }
    }
}

// int*** getColorCount(enum Color color)
// {
//     if (color == BLACK)
//     {
//         return blackCount;
//     }
//     if (color == WHITE)
//     {
//         return whiteCount;
//     }
//     return NULL;
// }   }
//     return NULL;
// }       return whiteCount;
//     }
//     return NULL;
// }   if (color == WHITE)
//     {
//         return whiteCount;
//     }
//     return NULL;
// }   return NULL;
// }   return NULL;
// }       return whiteCount;
//     }
//     return NULL;
// }   if (color == WHITE)
//     {
//         return whiteCount;
//     }
//     return NULL;
// }   return NULL;
// }   }
//     return NULL;
// }       return whiteCount;
//     }
//     return NULL;
// }   if (color == WHITE)
//     {
//         return whiteCount;
//     }
//     return NULL;
// }   return NULL;
// }