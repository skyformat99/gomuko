#include "GameMap.h"
#include <cstdlib>
#include "Config.h"

const int GameMap::directX[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int GameMap::directY[8] = {1, 1, 0, -1, -1, -1, 0, 1};

GameMap::GameMap()
{
}

GameMap::GameMap(enum Color **value)
{
    map = value;
}

bool GameMap::reachable(int x, int y)
{
    if (x < 0 || y >= Config::size)
        return false;
    if (x < 0 || y >= Config::size)
        return false;
    return true;
}

bool GameMap::reachable(struct Point point)
{
    if (point.x < 0 || point.y >= Config::size)
        return false;
    if (point.x < 0 || point.y >= Config::size)
        return false;
    return true;
}

enum Color **GameMap::getMap()
{
    return map;
}

enum Color GameMap::getColor(int x, int y)
{
    return map[x][y];
}

enum Color GameMap::getColor(struct Point point)
{
    return map[point.x][point.y];
}

void GameMap::setColor(struct Point point, enum Color color)
{
    map[point.x][point.y] = color;
}

bool GameMap::checkColors(enum Color color, struct Point point, int direct, int start, int end)
{
    int x = point.x + start * (directX[direct]);
    int y = point.x + start * (directY[direct]);
    for (int i = start; i <= end; i++)
    {
        if (!reachable(x, y))
        {
            return false;
        }
        if (getColor(x, y) != color)
        {
            return false;
        }
        x += directX[direct];
        y += directY[direct];
    }
    return true;
}

std::vector<struct Point> GameMap::getNeighbor(enum Color color)
{
    int range = 2;
    std::vector<struct Point> result;

    int signalOne[Config::size][Config::size];
    int signalCurrentColorTwo[Config::size][Config::size];
    int signalOtherColorTwo[Config::size][Config::size];

    for (int i = 0; i < Config::size; i++)
        for (int j = 0; j < Config::size; j++)
        {
            signalOne[i][j] = 0;
            signalCurrentColorTwo[i][j] = 0;
            signalOtherColorTwo[i][j] = 0;
        }

    for (int i = 0; i < Config::size; i++)
        for (int j = 0; j < Config::size; j++)
        {
            enum Color pointColor = getColor(i, j);
            if (pointColor != VOID)
            {
                int left = i - range >= 0 ? i - range : 0;
                int right = i + range < Config::size - 1 ? i + range : Config::size - 1;
                int top = j - range >= 0 ? j - range : 0;
                int button = j + range < Config::size - 1 ? j + range : Config::size - 1;
                for (int x = left; x <= right; x++)
                    for (int y = top; y <= button; y++)
                    {
                        if (getColor(x, y) == VOID)
                        {
                            if (std::max(std::abs(x - i), std::abs(y - j)) == 1)
                            {
                                signalOne[x][y]++;
                            }
                            if (std::max(std::abs(x - i), std::abs(y - j)) == 2)
                            {
                                if (std::abs(x - i) != 1 && std::abs(y - j) != 1)
                                {
                                    //只计算2连隔空下
                                    int tx = i, ty = j;
                                    if (x - i > 0)
                                        tx = i - 1;
                                    if (x - i < 0)
                                        tx = i + 1;
                                    if (y - j > 0)
                                        ty = j - 1;
                                    if (y - j < 0)
                                        ty = j + 1;
                                    if (reachable(tx, ty))
                                        if (getColor(tx, ty) == pointColor)
                                            if (pointColor == color)
                                                signalCurrentColorTwo[x][y]++;
                                    if (pointColor == getOtherColor(color))
                                        signalOtherColorTwo[x][y]++;
                                }
                            }
                        }
                    }
            }
        }
    for (int i = 0; i < Config::size; i++)
        for (int j = 0; j < Config::size; j++)
        {
            if (signalOne[i][j] > 0)
            {
                result.push_back(Point(i, j));
                continue;
            }
            if (signalCurrentColorTwo[i][j] > 0)
            {
                result.push_back(Point(i, j));
                continue;
            }
            if (signalOtherColorTwo[i][j] > 1)
            {
                result.push_back(Point(i, j));
            }
        }

    return result;
}
