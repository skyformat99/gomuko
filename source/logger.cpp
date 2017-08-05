#include "logger.h"
#include "time.h"

unsigned long currentTime = clock();

void printMapToConsole(enum Color **map)
{
    for (int i = 0; i < Config::size; i++)
    {
        for (int j = 0; j < Config::size; j++)
        {
            enum Color value = map[i][j];
            if (value == BLACK)
                printf("x");
            if (value == WHITE)
                printf("o");
            if (value == VOID)
                printf(".");
        }
        printf("\n");
    }
    printf("\n");
}

void printSelectPoint(struct Point point, int value, Counter counter)
{
    int second = (clock() - currentTime) / (CLOCKS_PER_SEC / 1000);
    printf("point %d %d value = %d count = %d comboCount = %d time = %d ms \n", point.x, point.y, value, counter.count, counter.comboCount, second);
}

void printPointVector(vector<struct Point> points)
{
    for (int i = 0; i < points.size(); i++)
        printf("(%d, %d) ", points[i].x, points[i].y);
    printf("\n");
}

void printPointSet(set<struct Point> points)
{
    set<struct Point>::iterator it;
    for (it = points.begin(); it != points.end(); it++)
        printf("(%d, %d) ", (*it).x, (*it).y);
    printf("\n");
}

void printAnalyzePoints(Analyzer analyzer)
{
    printf("FIVE A\n");
    printPointSet(analyzer.fiveAttack);
    printf("FOUR A\n");
    printPointSet(analyzer.fourAttack);
    printf("FOUR D\n");
    printPointSet(analyzer.fourDefence);
    printf("THREE A\n");
    printPointSet(analyzer.threeOpenAttack);
    printf("THREE D\n");
    printPointSet(analyzer.threeDefence);
    printf("TWO A\n");
    printPointSet(analyzer.twoAttack);
    printf("FULL\n");
    printPointSet(analyzer.fullPoints);
    printf("\n");
}