#include "LevelProcessor.h"

vector<struct Point> LevelProcessor::getExpandPoints(Analyzer data)
{
    vector<struct Point> result = selectSet(data);
    if (result.size() == 0)
    {
        result.push_back(Point(7, 7));
    }
    return removeRepeat(result);
}

vector<struct Point> LevelProcessor::selectSet(Analyzer data)
{
    //如果能连5，则连5
    if (data.fiveAttack.size() > 0)
    {
        return converToVector(data.fiveAttack);
    }
    //如果有对方冲4，则防冲4
    if (data.fourDefence.size() > 0)
    {
        return converToVector(data.fourDefence);
    }
    //如果有对方活3，则防活3或者冲四
    if (data.threeDefence.size() > 0)
    {
        vector<struct Point> pointFourAttack = converToVector(data.fourAttack);
        vector<struct Point> pointThreeDefence = converToVector(data.threeDefence);
        vector<struct Point> result;
        for (int i = 0; i < pointFourAttack.size(); i++)
            result.push_back(pointFourAttack[i]);
        for (int i = 0; i < pointThreeDefence.size(); i++)
            result.push_back(pointThreeDefence[i]);
        return result;
    }
    vector<struct Point> result;
    vector<struct Point> pointFourAttack = converToVector(data.fourAttack);
    for (int i = 0; i < pointFourAttack.size(); i++)
        result.push_back(pointFourAttack[i]);
    vector<struct Point> pointThreeOpenAttack = converToVector(data.threeOpenAttack);
    for (int i = 0; i < pointThreeOpenAttack.size(); i++)
        result.push_back(pointThreeOpenAttack[i]);
    vector<struct Point> pointTwoAttack = converToVector(data.twoAttack);
    for (int i = 0; i < pointTwoAttack.size(); i++)
        result.push_back(pointTwoAttack[i]);
    vector<struct Point> pointFullPoints = converToVector(data.fullPoints);
    for (int i = 0; i < pointFullPoints.size(); i++)
        result.push_back(pointFullPoints[i]);
    return result;
}

vector<struct Point> LevelProcessor::removeRepeat(vector<struct Point> points)
{
    set<struct Point> hash;
    vector<struct Point> result;
    for (int i = 0; i < points.size(); i++)
    {
        if (hash.find(points[i]) == hash.end())
        {
            hash.insert(points[i]);
            result.push_back(points[i]);
        }
    }
    return result;
}

vector<struct Point> LevelProcessor::converToVector(set<struct Point> points)
{
    vector<struct Point> result;
    set<struct Point>::iterator it;
    for (it = points.begin(); it != points.end(); it++)
    {
        result.push_back(*it);
    }
    return result;
}
