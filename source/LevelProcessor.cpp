#include "LevelProcessor.h"

vector<struct Point> LevelProcessor::getExpandPoints(Analyzer *data)
{
    vector<struct Point> result = selectSet(data);
    if (result.size() == 0)
    {
        result.push_back(Point(7, 7));
    }
    return removeRepeat(&result);
}

vector<struct Point> LevelProcessor::selectSet(Analyzer *data)
{
    //如果能连5，则连5
    if (data->fiveAttack.size() > 0)
    {
        return converToVector(&data->fiveAttack);
    }
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
    return converToVector(&data->fourAttack, &data->threeOpenAttack, &data->twoAttack, &data->fullPoints);
}

vector<struct Point> LevelProcessor::removeRepeat(vector<struct Point> *points)
{
    set<struct Point> hash;
    vector<struct Point> result;
    vector<struct Point> realPoints = *points;
    for (int i = 0; i < points->size(); i++)
    {
        if (hash.find(realPoints[i]) == hash.end())
        {
            hash.insert(realPoints[i]);
            result.push_back(realPoints[i]);
        }
    }
    return result;
}

vector<struct Point> LevelProcessor::converToVector(set<struct Point> *points)
{
    vector<struct Point> result;
    set<struct Point>::iterator it;
    for (it = points->begin(); it != points->end(); it++)
    {
        result.push_back(*it);
    }
    return result;
}

vector<struct Point> LevelProcessor::converToVector(set<struct Point> *points1, set<struct Point> *points2)
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

vector<struct Point> LevelProcessor::converToVector(set<struct Point> *points1, set<struct Point> *points2, set<struct Point> *points3, set<struct Point> *points4)
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
    for (it = points3->begin(); it != points3->end(); it++)
    {
        result.push_back(*it);
    }
    for (it = points4->begin(); it != points4->end(); it++)
    {
        result.push_back(*it);
    }
    return result;
}