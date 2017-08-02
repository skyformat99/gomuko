#ifndef _logger_
#define _logger_

#include <stdio.h>
#include "Config.h"
#include "Analyzer.h"
#include "struct/Color.cpp"
#include "struct/Point.cpp"
#include "struct/Counter.cpp"
#include "vector"
#include "set"

using namespace std;

void printMapToConsole(enum Color **map);

void printSelectPoint(struct Point point, int value, Counter counter);

void printPointVector(vector<struct Point> points);

void printAnalyzePoints(Analyzer analyzer);

#endif