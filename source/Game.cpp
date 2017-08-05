#include "Game.h"
#include "WinChecker.h"

void Game::init(enum Color **map, Config config)
{
    gameMap = GameMap(map);
    this->config = config;
}

Result *Game::search(enum Color color)
{
    result.reset();
    counter.clear();
    aiColor = color;
    if (WinChecker::win(gameMap) != VOID)
    {
        return NULL;
    }
    //积分预处理
    score.initScore(gameMap.getMap(), aiColor);
    //只有一个扩展点的情形直接返回
    vector<struct Point> neighbor = gameMap.getNeighbor(color);
    Analyzer data = Analyzer(&gameMap, color, &neighbor, &score);
    vector<struct Point> points = levelProcessor.getExpandPoints(&data);
    if (points.size() == 1)
    {
        result.add(points[0], 0);
        return &result;
    }
    dfsScore(config.searchDeep, color, Config::MAX_VALUE, 0);
    return &result;
}

int Game::dfsScore(int level, enum Color color, int parentMin, int parentMax)
{
    //斩杀剪枝
    if (level == 0)
    {
        if (color == aiColor)
        {
            if (Finisher::canKill(&gameMap, color, config.comboDeep, &score))
            {
                return Config::MAX_VALUE;
            }
        }
    }
    if (level == 1)
    {
        //谨慎处理败北的情形
        if (color != aiColor)
        {
            if (Finisher::canKill(&gameMap, color, config.comboDeep, &score))
            {
                return Config::MIN_VALUE;
            }
        }
    }
    //叶子分数计算
    if (level == 0)
    {
        return getScore();
    }
    //分析棋型
    vector<struct Point> neighbor = gameMap.getNeighbor(color);
    Analyzer data = Analyzer(&gameMap, color, &neighbor, &score);
    //输赢判定
    if (data.fiveAttack.size() > 0)
    {
        if (color == aiColor)
            return Config::MAX_VALUE;
        if (color == getOtherColor(aiColor))
            return Config::MIN_VALUE;
    }
    //计算扩展节点
    vector<struct Point> points = levelProcessor.getExpandPoints(&data);
    //进度计算
    if (level == config.searchDeep)
    {
        counter.allStep = points.size();
    }
    //遍历扩展节点
    int extreme = color == aiColor ? Config::MIN_VALUE : Config::MAX_VALUE;
    for (int i = 0; i < points.size(); i++)
    {
        struct Point point = points[i];
        setColor(point, color, VOID, aiColor);
        if (color == aiColor)
        {
            int value = dfsScore(level - 1, getOtherColor(color), 0, extreme);
            if (value > parentMin)
            {
                setColor(point, VOID, color, aiColor);
                return value;
            }
            if (level == config.searchDeep)
            {
                if (value >= extreme)
                {
                    result.add(point, value);
                }
                counter.count++;
                if (config.debug)
                {
                    printSelectPoint(point, value, counter);
                }
            }
            if (value > extreme)
            {
                extreme = value;
                //如果能赢了，则直接剪掉后面的情形
                if (extreme == Config::MAX_VALUE)
                {
                    setColor(point, VOID, color, aiColor);
                    return extreme;
                }
            }
        }
        if (color != aiColor)
        {
            int value = dfsScore(level - 1, getOtherColor(color), extreme, 0);
            if (value < parentMax)
            {
                setColor(point, VOID, color, aiColor);
                return value;
            }
            if (value < extreme)
            {
                extreme = value;
                //如果已经输了，则直接剪掉后面的情形
                if (extreme == Config::MIN_VALUE)
                {
                    setColor(point, VOID, color, aiColor);
                    return extreme;
                }
            }
        }
        setColor(point, VOID, color, aiColor);
    }
    return extreme;
}

void Game::setColor(struct Point point, enum Color color, enum Color forwardColor, enum Color aiColor)
{
    score.setColorAndUpdate(point, color, forwardColor, aiColor);
    gameMap.setColor(point, color);
}

int Game::getScore()
{
    counter.count++;
    return score.getMapScore();
}
