#include "LevelProcessor.h"
#include "logger.h"

vector<struct Point> *LevelProcessor::getExpandPoints(Analyzer *data)
{
    result.clear();
    selectSet(data);
    if (result.size() == 0)
    {
        result.push_back(Point(7, 7));
    }
    removeRepeat();
    return &finalResult;
}

vector<struct Point> *LevelProcessor::getExpandPoints(GameMap *gameMap, enum Color color)
{
    result.clear();
    result = *(gameMap->getNeighbor(color));
    return &result;
}

void LevelProcessor::selectSet(Analyzer *data)
{
    //如果能连5，则连5
    if (data->fiveAttack.size() > 0)
    {
        converToVector(&(data->fiveAttack), &result);
        return;
    }
    //如果有对方冲4，则防冲4
    if (data->fourDefence.size() > 0)
    {
        converToVector(&(data->fourDefence), &result);
        return;
    }
    //如果有对方活3，则防活3或者冲四
    if (data->threeDefence.size() > 0)
    {
        pointFourAttack.clear();
        pointThreeDefence.clear();
        converToVector(&(data->fourAttack), &pointFourAttack);
        converToVector(&(data->threeDefence), &pointThreeDefence);
        for (int i = 0; i < pointFourAttack.size(); i++)
            result.push_back(pointFourAttack[i]);
        for (int i = 0; i < pointThreeDefence.size(); i++)
            result.push_back(pointThreeDefence[i]);
        return;
    }
    converToVector(&(data->fourAttack), &pointFourAttack);
    for (int i = 0; i < pointFourAttack.size(); i++)
        result.push_back(pointFourAttack[i]);
    converToVector(&(data->threeOpenAttack), &pointThreeOpenAttack);
    for (int i = 0; i < pointThreeOpenAttack.size(); i++)
        result.push_back(pointThreeOpenAttack[i]);
    converToVector(&(data->twoAttack), &pointTwoAttack);
    for (int i = 0; i < pointTwoAttack.size(); i++)
        result.push_back(pointTwoAttack[i]);
    converToVector(&(data->fullPoints), &pointFullPoints);
    for (int i = 0; i < pointFullPoints.size(); i++)
        result.push_back(pointFullPoints[i]);
}

void LevelProcessor::removeRepeat()
{
    hash.clear();
    finalResult.clear();
    for (int i = 0; i < result.size(); i++)
    {
        if (hash.find(result[i]) == hash.end())
        {
            hash.insert(result[i]);
            finalResult.push_back(result[i]);
        }
    }
}

void LevelProcessor::converToVector(set<struct Point> *points, vector<struct Point> *target)
{
    set<struct Point>::iterator it;
    for (it = points->begin(); it != points->end(); it++)
    {
        target->push_back(*it);
    }
}
