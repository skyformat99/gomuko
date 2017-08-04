#include "Analyzer.h"
#include "struct/Color.cpp"
#include "struct/Point.cpp"
#include "GameMap.h"
#include "Score.h"
#include "mapDriver.h"
#include "logger.h"

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
    score.initScore(map, WHITE);
    Analyzer analyzer = Analyzer(&gameMap, WHITE, gameMap.getNeighbor(WHITE), &score);
    printf("FIVE A\n");
    print(analyzer.fiveAttack);
    printf("FOUR A\n");
    print(analyzer.fourAttack);
    printf("FOUR D\n");
    print(analyzer.fourDefence);
    printf("THREE A\n");
    print(analyzer.threeOpenAttack);
    printf("THREE D\n");
    print(analyzer.threeDefence);
    printf("TWO A\n");
    print(analyzer.twoAttack);
    printf("FULL\n");
    print(analyzer.fullPoints);
    return 0;
}
