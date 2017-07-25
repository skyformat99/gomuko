#include "game.c"
#include "stdio.h"
#include "helper/mapDriver.c"

int main()
{
    enum Color **map = readMap();
    printMapToConsole(map);
}