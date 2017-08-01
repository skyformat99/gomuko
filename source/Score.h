#ifndef _SCORE_
#define _SCORE_

#include "gameMap.h"
#include "Config.h"

class Score
{
  public:
    void initScore(enum Color **map, enum Color aiColor);

    int getMapScore();

    void setColorAndUpdate(struct Point point, enum Color color, enum Color forwardColor, enum Color aiColor);

  private:
    const static int ONE = 1;
    const static int TWO = 10;
    const static int THREE = 20;
    const static int FOUR = 50;

    const static int directX[4];
    const static int directY[4];
    
    //使用动态规划
    //定义：    f[i][j][k] 表示以i,j为终点，在方向k上的统计
    //转移方程: f[i][j][k] = a[i][j][k] + f[i-dx[k]][j-dy[k]][k]
    int blackCount[Config::size][Config::size][4];
    int whiteCount[Config::size][Config::size][4];

    int value;

    int getValueByCount(int blackCount, int whiteCount, enum Color color);
};

#endif