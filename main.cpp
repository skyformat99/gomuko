#include "stdio.h"
#include "source/game.cpp"
#include "source/mapDriver.h"

int main()
{
    enum Color **map = readMap();
    printMapToConsole(map);
}