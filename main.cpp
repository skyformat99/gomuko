#include "stdio.h"
#include "source/Game.h"
#include "source/mapDriver.h"
#include "source/struct/Color.cpp"
#include "source/struct/Result.cpp"
#include "source/Config.h"
#include "source/logger.h"

int main()
{
    enum Color **map = readMap();
    Game game = Game();
    Config config;
    config.searchDeep = 6;
    printf("%d\n", config.debug);
    game.init(map, config);
    printMapToConsole(map);
    Result *result = game.search(BLACK);
    printf("%d %d\n", result->getPoint()->x, result->getPoint()->y);
}