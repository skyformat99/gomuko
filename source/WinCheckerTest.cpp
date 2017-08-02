#include "WinChecker.h"
#include "mapDriver.h"
#include "struct/Color.cpp"
#include <stdio.h>
#include <string>
#include "logger.h"

int main()
{
    enum Color **map = readMap();
    printMapToConsole(map);
    GameMap gameMap = GameMap(map);
    enum Color color = WinChecker::win(gameMap);
    std::string result;
    if (color == VOID)
        result = "NULL";
    if (color == BLACK)
        result = "BLACK";
    if (color == WHITE)
        result = "WHITE";
    printf("result = %s\n", result.c_str());
    return 0;
}