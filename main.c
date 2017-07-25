#include "game.c"
#include "stdio.h"
#include "helper/mapDriver.h"

int main()
{
    enum Color **map = readMap();
    printMapToConsole(map);
}