#ifndef _logger_
#define _logger_

#include <stdio.h>
#include "Config.h"
#include "struct/Color.cpp"
#include "struct/Point.cpp"
#include "struct/Counter.cpp"

void printMapToConsole(enum Color **map);

void printSelectPoint(struct Point point, int value, Counter counter);

#endif