#include "GameMap.h"
#include "mapDriver.h"
#include "struct/Color.cpp"
#include "LevelProcessor.h"

int main()
{
    enum Color **map = readMap();
    GameMap gameMap = GameMap(map);
    printMapToConsole(map);

    LevelProcessor levelProcessor;
    std::vector<struct Point> points = levelProcessor.getExpandPoints(gameMap, BLACK);
    printf("%ld\n", points.size());
    for (int i = 0; i < points.size(); i++)
    {
        printf("%d %d\n", points[i].x, points[i].y);
    }
    return 0;
}