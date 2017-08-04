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
    vector<struct Point> points = *(gameMap.getNeighbor(WHITE));
    Score score = Score();
    score.initScore(map, WHITE);
    Analyzer analyzer;
    analyzer.init(&gameMap, &score);
    for (int direct = 0; direct < 4; direct++)
        for (int i = 0; i < Config::size; i++)
            for (int j = 0; j < Config::size; j++)
            {
                printf("point %d %d ", i, j);
                printf("BLACK: ");
                if (analyzer.fiveAttackSignal[BLACK][i][j][direct])
                    printf("5A ");
                if (analyzer.fourAttackSignal[BLACK][i][j][direct])
                    printf("4A ");
                if (analyzer.fourDefenceSignal[BLACK][i][j][direct])
                    printf("4D ");
                if (analyzer.threeAttackSignal[BLACK][i][j][direct])
                    printf("3A ");
                if (analyzer.threeDefenceSignal[BLACK][i][j][direct])
                    printf("3D ");
                if (analyzer.twoAttackSignal[BLACK][i][j][direct])
                    printf("2A ");

                printf("WHITE: ");
                if (analyzer.fiveAttackSignal[WHITE][i][j][direct])
                    printf("5A ");
                if (analyzer.fourAttackSignal[WHITE][i][j][direct])
                    printf("4A ");
                if (analyzer.fourDefenceSignal[WHITE][i][j][direct])
                    printf("4D ");
                if (analyzer.threeAttackSignal[WHITE][i][j][direct])
                    printf("3A ");
                if (analyzer.threeDefenceSignal[WHITE][i][j][direct])
                    printf("3D ");
                if (analyzer.twoAttackSignal[WHITE][i][j][direct])
                    printf("2A ");

                printf("\n");
            }

    analyzer.buildSet(WHITE, &points);
    printAnalyzePoints(analyzer);
    return 0;
}
