#include "Analyzer.h"
#include "struct/Color.cpp"
#include "struct/Point.cpp"
#include "GameMap.h"
#include "Score.h"
#include "mapDriver.h"
#include "logger.h"
#include "Finisher.h"

using namespace std;

void print(set<struct Point> points)
{
    set<struct Point>::iterator it;
    for (it = points.begin(); it != points.end(); it++)
        printf("(%d, %d) ", (*it).x, (*it).y);
    printf("\n");
}

int main()
{
    enum Color **map = readMap();
    printMapToConsole(map);
    GameMap gameMap = GameMap(map);
    Score score = Score();
    enum Color color = WHITE;
    score.initScore(map, color);
    vector<struct Point> neighbor = gameMap.getNeighbor(color);
    Finisher finisher;
    Counter counter;
    Config config;
    config.comboDeep = 11;
    finisher.init(&gameMap, &score, &counter, &config);
    bool result = finisher.canKill(color);
    printf("%d\n", result);
    return 0;
}
