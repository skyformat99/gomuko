#include "LevelProcessor.h"

std::vector<struct Point> LevelProcessor::getExpandPoints(GameMap gameMap, enum Color color)
{
    std::vector<struct Point> result = gameMap.getNeighbor(color);
    if (result.size() == 0)
    {
        result.push_back(Point(7, 7));
    }
    return result;
}
