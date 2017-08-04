#include "Analyzer.h"
#include "logger.h"

const int Analyzer::directX[4] = {0, 1, 1, 1};
const int Analyzer::directY[4] = {1, 1, 0, -1};

void Analyzer::reset(GameMap *gameMap, enum Color color, vector<struct Point> *points, Score *score)
{
    fiveAttack.clear();
    fourAttack.clear();
    fourDefence.clear();
    threeOpenAttack.clear();
    threeDefence.clear();
    twoAttack.clear();
    fullPoints.clear();
    for (int p = 0; p < (*points).size(); p++)
    {
        struct Point point = (*points)[p];
        fullPoints.insert(point);
        for (int i = 0; i < 4; i++)
        {
            int x = point.x;
            int y = point.y;
            enum Color otherColor = getOtherColor(color);
            for (int k = 0; k < 5; k++)
            {
                if (score->getColorCount(otherColor)[x][y][i] == 0 && score->getColorCount(color)[x][y][i] == 4)
                {
                    fiveAttack.insert(point);
                }
                if (score->getColorCount(otherColor)[x][y][i] == 0 && score->getColorCount(color)[x][y][i] == 3)
                {
                    fourAttack.insert(point);
                }
                if (score->getColorCount(otherColor)[x][y][i] == 4 && score->getColorCount(color)[x][y][i] == 0)
                {
                    fourDefence.insert(point);
                }
                if (score->getColorCount(otherColor)[x][y][i] == 0 && score->getColorCount(color)[x][y][i] == 2)
                {
                    if (k != 0 && k != 4)
                    {
                        int headX = x - directX[i] * 4;
                        int headY = y - directY[i] * 4;
                        if (GameMap::reachable(headX, headY))
                        {
                            enum Color headColor = gameMap->getColor(headX, headY);
                            enum Color tailColor = gameMap->getColor(x, y);
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
                                    enum Color sideColor = gameMap->getColor(sideX, sideY);
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
                                    enum Color sideColor = gameMap->getColor(sideX, sideY);
                                    if (sideColor == VOID)
                                    {
                                        threeOpenAttack.insert(point);
                                    }
                                }
                            }
                        }
                    }
                }
                if (score->getColorCount(otherColor)[x][y][i] == 3 && score->getColorCount(color)[x][y][i] == 0)
                {
                    int headX = x - directX[i] * 4;
                    int headY = y - directY[i] * 4;
                    if (GameMap::reachable(headX, headY))
                    {
                        enum Color headColor = gameMap->getColor(headX, headY);
                        enum Color tailColor = gameMap->getColor(x, y);
                        if (headColor != VOID && tailColor == VOID)
                        {
                            if (gameMap->getColor(x - directX[i], y - directY[i]) != VOID)
                            {
                                int sideX = headX - directX[i];
                                int sideY = headY - directY[i];
                                if (GameMap::reachable(sideX, sideY))
                                {
                                    enum Color sideColor = gameMap->getColor(sideX, sideY);
                                    if (sideColor == VOID)
                                    {
                                        threeDefence.insert(point);
                                    }
                                }
                            }
                        }
                        if (tailColor != VOID && headColor == VOID)
                        {
                            if (gameMap->getColor(headX + directX[i], headY + directY[i]) != VOID)
                            {
                                int sideX = x + directX[i];
                                int sideY = y + directY[i];
                                if (GameMap::reachable(sideX, sideY))
                                {
                                    enum Color sideColor = gameMap->getColor(sideX, sideY);
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
                if (score->getColorCount(otherColor)[x][y][i] == 1 && score->getColorCount(color)[x][y][i] == 0)
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

void Analyzer::update(struct Point point, enum Color color, int direct)
{
    fiveAttackSignal[color][point.x][point.y][direct] = false;
    fourAttackSignal[color][point.x][point.y][direct] = false;
    fourDefenceSignal[color][point.x][point.y][direct] = false;
    threeAttackSignal[color][point.x][point.y][direct] = false;
    threeDefenceSignal[color][point.x][point.y][direct] = false;
    twoAttackSignal[color][point.x][point.y][direct] = false;

    int x = point.x;
    int y = point.y;
    enum Color otherColor = getOtherColor(color);
    for (int k = 0; k < 5; k++)
    {
        if (score->getColorCount(otherColor)[x][y][direct] == 0 && score->getColorCount(color)[x][y][direct] == 4)
        {
            fiveAttackSignal[color][point.x][point.y][direct] = true;
        }
        if (score->getColorCount(otherColor)[x][y][direct] == 0 && score->getColorCount(color)[x][y][direct] == 3)
        {
            fourAttackSignal[color][point.x][point.y][direct] = true;
        }
        if (score->getColorCount(otherColor)[x][y][direct] == 4 && score->getColorCount(color)[x][y][direct] == 0)
        {
            fourDefenceSignal[color][point.x][point.y][direct] = true;
        }
        if (score->getColorCount(otherColor)[x][y][direct] == 0 && score->getColorCount(color)[x][y][direct] == 2)
        {
            if (k != 0 && k != 4)
            {
                int headX = x - directX[direct] * 4;
                int headY = y - directY[direct] * 4;
                if (GameMap::reachable(headX, headY))
                {
                    enum Color headColor = gameMap->getColor(headX, headY);
                    enum Color tailColor = gameMap->getColor(x, y);
                    if (tailColor == VOID && headColor == VOID)
                    {
                        threeAttackSignal[color][point.x][point.y][direct] = true;
                    }
                    if (headColor == VOID && tailColor != VOID)
                    {
                        int sideX = x + directX[direct];
                        int sideY = y + directY[direct];
                        if (GameMap::reachable(sideX, sideY))
                        {
                            enum Color sideColor = gameMap->getColor(sideX, sideY);
                            if (sideColor == VOID)
                            {
                                threeAttackSignal[color][point.x][point.y][direct] = true;
                            }
                        }
                    }
                    if (headColor != VOID && tailColor == VOID)
                    {
                        int sideX = headX - directX[direct];
                        int sideY = headY - directY[direct];
                        if (GameMap::reachable(sideX, sideY))
                        {
                            enum Color sideColor = gameMap->getColor(sideX, sideY);
                            if (sideColor == VOID)
                            {
                                threeAttackSignal[color][point.x][point.y][direct] = true;
                            }
                        }
                    }
                }
            }
        }
        if (score->getColorCount(otherColor)[x][y][direct] == 3 && score->getColorCount(color)[x][y][direct] == 0)
        {
            int headX = x - directX[direct] * 4;
            int headY = y - directY[direct] * 4;
            if (GameMap::reachable(headX, headY))
            {
                enum Color headColor = gameMap->getColor(headX, headY);
                enum Color tailColor = gameMap->getColor(x, y);
                if (headColor != VOID && tailColor == VOID)
                {
                    if (gameMap->getColor(x - directX[direct], y - directY[direct]) != VOID)
                    {
                        int sideX = headX - directX[direct];
                        int sideY = headY - directY[direct];
                        if (GameMap::reachable(sideX, sideY))
                        {
                            enum Color sideColor = gameMap->getColor(sideX, sideY);
                            if (sideColor == VOID)
                            {
                                threeDefenceSignal[color][point.x][point.y][direct] = true;
                            }
                        }
                    }
                }
                if (tailColor != VOID && headColor == VOID)
                {
                    if (gameMap->getColor(headX + directX[direct], headY + directY[direct]) != VOID)
                    {
                        int sideX = x + directX[direct];
                        int sideY = y + directY[direct];
                        if (GameMap::reachable(sideX, sideY))
                        {
                            enum Color sideColor = gameMap->getColor(sideX, sideY);
                            if (sideColor == VOID)
                            {
                                threeDefenceSignal[color][point.x][point.y][direct] = true;
                            }
                        }
                    }
                }
                if (headColor == VOID && tailColor == VOID)
                {
                    threeDefenceSignal[color][point.x][point.y][direct] = true;
                }
            }
        }
        if (score->getColorCount(otherColor)[x][y][direct] == 1 && score->getColorCount(color)[x][y][direct] == 0)
        {
            twoAttackSignal[color][point.x][point.y][direct] = true;
        }
        x += directX[direct];
        y += directY[direct];
        if (!GameMap::reachable(x, y))
        {
            break;
        }
    }
}

void Analyzer::changePoint(struct Point point)
{
    // for (int i = 0; i < Config::size; i++)
    //     for (int j = 0; j < Config::size; j++)
    //         for (int direct = 0; direct < 4; direct++)
    //         {
    //             if (gameMap->getColor(i, j) == VOID)
    //             {
    //                 struct Point newPoint = Point(i, j);
    //                 update(newPoint, BLACK, direct);
    //                 update(newPoint, WHITE, direct);
    //             }
    //         }
    for (int i = 0; i < 4; i++)
    {
        for (int k = -4; k <= 4; k++)
        {
            int x = point.x + k * directX[i];
            int y = point.y + k * directY[i];
            if (GameMap::reachable(x, y))
            {
                if (gameMap->getColor(x, y) == VOID)
                {
                    struct Point newPoint = Point(x, y);
                    update(newPoint, BLACK, i);
                    update(newPoint, WHITE, i);
                }
            }
        }
    }
}

void Analyzer::init(GameMap *gameMap, Score *score)
{
    this->gameMap = gameMap;
    this->score = score;
    for (int k = 0; k < 2; k++)
        for (int i = 0; i < Config::size; i++)
            for (int j = 0; j < Config::size; j++)
                for (int direct = 0; direct < 4; direct++)
                {
                    fiveAttackSignal[k][i][j][direct] = false;
                    fourAttackSignal[k][i][j][direct] = false;
                    fourDefenceSignal[k][i][j][direct] = false;
                    threeAttackSignal[k][i][j][direct] = false;
                    threeDefenceSignal[k][i][j][direct] = false;
                    twoAttackSignal[k][i][j][direct] = false;
                }
    for (int i = 0; i < Config::size; i++)
        for (int j = 0; j < Config::size; j++)
        {
            enum Color color = gameMap->getColor(i, j);
            if (color != VOID)
            {
                changePoint(Point(i, j));
            }
        }
}

void Analyzer::buildSet(enum Color color, vector<struct Point> *points)
{
    fiveAttack.clear();
    fourAttack.clear();
    fourDefence.clear();
    threeOpenAttack.clear();
    threeDefence.clear();
    twoAttack.clear();
    fullPoints.clear();
    for (int i = 0; i < points->size(); i++)
    {
        struct Point point = (*points)[i];
        fullPoints.insert(point);
        for (int direct = 0; direct < 4; direct++)
        {
            if (fiveAttackSignal[color][point.x][point.y][direct])
                fiveAttack.insert(point);
            if (fourAttackSignal[color][point.x][point.y][direct])
                fourAttack.insert(point);
            if (fourDefenceSignal[color][point.x][point.y][direct])
                fourDefence.insert(point);
            if (threeAttackSignal[color][point.x][point.y][direct])
                threeOpenAttack.insert(point);
            if (threeDefenceSignal[color][point.x][point.y][direct])
                threeDefence.insert(point);
            if (twoAttackSignal[color][point.x][point.y][direct])
                twoAttack.insert(point);
        }
    }
}