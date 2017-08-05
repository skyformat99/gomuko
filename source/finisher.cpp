#include "Finisher.h"

void Finisher::init(GameMap *gameMap, Score *score, Counter *counter, Config *config)
{
    this->gameMap = gameMap;
    this->score = score;
    this->counter = counter;
    this->config = config;
}

struct Point *Finisher::canKill(enum Color targetColor)
{
    if (dfsKill(targetColor, targetColor, config->comboDeep))
        return &result;
    return NULL;
}

bool Finisher::dfsKill(enum Color color, enum Color targetColor, int level)
{
    if (level == 0)
    {
        counter->comboCount++;
        return false;
    }
    vector<struct Point> rangePoints = gameMap->getNeighbor(color);
    Analyzer data = Analyzer(gameMap, color, &rangePoints, score);
    if (color == targetColor)
    {
        if (data.fiveAttack.size() > 0)
        {
            counter->comboCount++;
            return true;
        }
        vector<struct Point> points = getComboAttackPoints(color, &data);
        for (int i = 0; i < points.size(); i++)
        {
            struct Point point = points[i];
            setColor(point, color, VOID, targetColor);
            bool value = dfsKill(getOtherColor(color), targetColor, level - 1);
            if (value)
            {
                if (level == config->comboDeep)
                {
                    result = point;
                }
                setColor(point, VOID, color, targetColor);
                return true;
            }
            setColor(point, VOID, color, targetColor);
        }
        return false;
    }
    else
    {
        if (data.fiveAttack.size() > 0)
        {
            counter->comboCount++;
            return false;
        }
        vector<struct Point> points = getComboDefencePoints(color, &data);
        //如果没有能防的则结束
        if (points.size() == 0)
        {
            return false;
        }
        for (int i = 0; i < points.size(); i++)
        {
            struct Point point = points[i];
            setColor(point, color, VOID, targetColor);
            bool value = dfsKill(getOtherColor(color), targetColor, level - 1);
            if (!value)
            {
                setColor(point, VOID, color, targetColor);
                return false;
            }
            setColor(point, VOID, color, targetColor);
        }
        return true;
    }
}

vector<struct Point> Finisher::getComboAttackPoints(enum Color color, Analyzer *data)
{
    //如果有对方冲4，则防冲4
    if (data->fourDefence.size() > 0)
    {
        return converToVector(&data->fourDefence);
    }
    //如果有对方活3，冲四
    if (data->threeDefence.size() > 0)
    {
        return converToVector(&data->fourAttack);
    }
    return converToVector(&data->fourAttack, &data->threeOpenAttack);
}

vector<struct Point> Finisher::getComboDefencePoints(enum Color color, Analyzer *data)
{
    //如果有对方冲4，则防冲4
    if (data->fourDefence.size() > 0)
    {
        return converToVector(&data->fourDefence);
    }
    //如果有对方活3，则防活3或者冲四
    if (data->threeDefence.size() > 0)
    {
        return converToVector(&data->fourAttack, &data->threeDefence);
    }
    vector<struct Point> result;
    return result;
}

void Finisher::setColor(Point point, Color color, Color forwardColor, Color aiColor)
{
    score->setColorAndUpdate(point, color, forwardColor, aiColor);
    gameMap->setColor(point, color);
}

vector<struct Point> Finisher::converToVector(set<struct Point> *points)
{
    vector<struct Point> result;
    set<struct Point>::iterator it;
    for (it = points->begin(); it != points->end(); it++)
    {
        result.push_back(*it);
    }
    return result;
}

vector<struct Point> Finisher::converToVector(set<struct Point> *points1, set<struct Point> *points2)
{
    vector<struct Point> result;
    set<struct Point>::iterator it;
    for (it = points1->begin(); it != points1->end(); it++)
    {
        result.push_back(*it);
    }
    for (it = points2->begin(); it != points2->end(); it++)
    {
        result.push_back(*it);
    }
    return result;
}