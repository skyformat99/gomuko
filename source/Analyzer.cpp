#include "Analyzer.h"
#include "logger.h"

const int Analyzer::directX[4] = {0, 1, 1, 1};
const int Analyzer::directY[4] = {1, 1, 0, -1};

Analyzer::Analyzer(GameMap gameMap, enum Color color, vector<struct Point> points, Score score)
{
    for (int p = 0; p < points.size(); p++)
    {
        struct Point point = points[p];
        fullPoints.insert(point);
        for (int i = 0; i < 4; i++)
        {
            int x = point.x;
            int y = point.y;
            enum Color otherColor = getOtherColor(color);
            for (int k = 0; k < 5; k++)
            {
                if (score.getColorCount(otherColor)[x][y][i] == 0 && score.getColorCount(color)[x][y][i] == 4)
                {
                    fiveAttack.insert(point);
                }
                if (score.getColorCount(otherColor)[x][y][i] == 0 && score.getColorCount(color)[x][y][i] == 3)
                {
                    fourAttack.insert(point);
                }
                if (score.getColorCount(otherColor)[x][y][i] == 4 && score.getColorCount(color)[x][y][i] == 0)
                {
                    fourDefence.insert(point);
                }
                if (score.getColorCount(otherColor)[x][y][i] == 0 && score.getColorCount(color)[x][y][i] == 2)
                {
                    if (k != 0 && k != 4)
                    {
                        int headX = x - directX[i] * 4;
                        int headY = y - directY[i] * 4;
                        if (GameMap::reachable(headX, headY))
                        {
                            enum Color headColor = gameMap.getColor(headX, headY);
                            enum Color tailColor = gameMap.getColor(x, y);
                            if (tailColor == VOID && headColor == VOID)
                            {
                                threeOpenAttack.insert(point);
                            }
                            if (headColor == VOID && tailColor != VOID)
                            {
                                int sideX = x + directX[i];
                                int sideY = y + directY[i];
                                if (GameMap::reachable(sideX, sideY))
                                {
                                    enum Color sideColor = gameMap.getColor(sideX, sideY);
                                    if (sideColor == VOID)
                                    {
                                        threeOpenAttack.insert(point);
                                    }
                                }
                            }
                            if (headColor != VOID && tailColor == VOID)
                            {
                                int sideX = headX - directX[i];
                                int sideY = headY - directY[i];
                                if (GameMap::reachable(sideX, sideY))
                                {
                                    enum Color sideColor = gameMap.getColor(sideX, sideY);
                                    if (sideColor == VOID)
                                    {
                                        threeOpenAttack.insert(point);
                                    }
                                }
                            }
                        }
                    }
                }
                if (score.getColorCount(otherColor)[x][y][i] == 3 && score.getColorCount(color)[x][y][i] == 0)
                {
                    int headX = x - directX[i] * 4;
                    int headY = y - directY[i] * 4;
                    if (GameMap::reachable(headX, headY))
                    {
                        enum Color headColor = gameMap.getColor(headX, headY);
                        enum Color tailColor = gameMap.getColor(x, y);
                        if (headColor != VOID && tailColor == VOID)
                        {
                            if (gameMap.getColor(x - directX[i], y - directY[i]) != VOID)
                            {
                                int sideX = headX - directX[i];
                                int sideY = headY - directY[i];
                                if (GameMap::reachable(sideX, sideY))
                                {
                                    enum Color sideColor = gameMap.getColor(sideX, sideY);
                                    if (sideColor == VOID)
                                    {
                                        threeDefence.insert(point);
                                    }
                                }
                            }
                        }
                        if (tailColor != VOID && headColor == VOID)
                        {
                            if (gameMap.getColor(headX + directX[i], headY + directY[i]) != VOID)
                            {
                                int sideX = x + directX[i];
                                int sideY = y + directY[i];
                                if (GameMap::reachable(sideX, sideY))
                                {
                                    enum Color sideColor = gameMap.getColor(sideX, sideY);
                                    if (sideColor == VOID)
                                    {
                                        threeDefence.insert(point);
                                    }
                                }
                            }
                        }
                        if (headColor == VOID && tailColor == VOID)
                        {
                            threeDefence.insert(point);
                        }
                    }
                }
                if (score.getColorCount(otherColor)[x][y][i] == 1 && score.getColorCount(color)[x][y][i] == 0)
                {
                    twoAttack.insert(point);
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
}
