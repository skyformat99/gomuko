#include "WinChecker.h"

enum Color WinChecker::win(GameMap gameMap)
{
    for (int i = 0; i < Config::size; i++)
        for (int j = 0; j < Config::size; j++)
        {
            struct Point point = Point(i, j);
            if (gameMap.getColor(point) != VOID)
            {
                for (int direct = 0; direct < 4; direct++)
                {
                    enum Color color = gameMap.getColor(point);
                    if (gameMap.checkColors(color, point, direct, 0, 4))
                    {
                        return gameMap.getColor(point);
                    }
                }
            }
        }
    return VOID;
}
