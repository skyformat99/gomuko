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
    score.initScore(map, BLACK);
    vector<struct Point> neighbor = gameMap.getNeighbor(BLACK);
    Finisher finisher;
    Counter counter;
    finisher.init(&gameMap, &score, &counter);
    bool result = finisher.canKill(BLACK, 7);
    printf("%d\n", result);
    return 0;
}
