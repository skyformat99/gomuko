#include "stdio.h"
#include "source/Game.h"
#include "source/mapDriver.h"
#include "source/struct/Color.cpp"
#include "source/struct/Result.cpp"
#include "source/Config.h"

int main()
{
    enum Color **map = readMap();
    Game game = Game();
    Config config;
    config.searchDeep = 4;
    game.init(map, config);
    Result *result = game.search(BLACK);
    printf("SEARCH FINISH \n");
    printMapToConsole(map);
    printf("%d %d\n", result->getPoint()->x, result->getPoint()->y);
}