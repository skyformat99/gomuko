#ifndef _GAME_MAP_
#define _GAME_MAP_

#include <vector>
#include "struct/Point.cpp"
#include "struct/Color.cpp"

class GameMap
{
  public:
    GameMap(enum Color **value);

    enum Color **getMap();

    static bool reachable(int x, int y);

    static bool reachable(struct Point point);

    enum Color getColor(int x, int y);

    enum Color getColor(struct Point point);

    void setColor(struct Point point, enum Color color);

    bool checkColors(enum Color color, struct Point point, int direct, int start, int end);

    std::vector<struct Point> getNeighbor(enum Color color);

  private:
    const static int directX[8];
    const static int directY[8];

    static const int MIN_VALUE = -10000000;

    enum Color **map;
};

#endif