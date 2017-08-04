#ifndef _Finisher_
#define _Finisher_

class Finisher
{
  public:
    static bool canKill(GameMap *gameMap, enum Color targetColor, int deep, Score *score)
    {
        bool result = dfsKill(gameMap, targetColor, targetColor, deep, score, NULL);
        return result;
    }

  private:
    static bool dfsKill(GameMap *gameMap, enum Color color, enum Color targetColor, int level, Score *score, Point lastPoint)
    {
        if (level == 0)
        {
            return false;
        }
        //连招只按相邻直线路径计算
        vector<struct Point> rangePoints;
        if (lastPoint == NULL)
        {
            rangePoints = gameMap->getNeighbor(color);
        }
        else
        {
            rangePoints = gameMap->getOnePointLine(lastPoint);
        }
        Analyzer data = Analyzer(gameMap, color, targetColor, rangePoints, score);
        if (color == targetColor)
        {
            if (data.getFiveAttack.size() > 0)
            {
                return true;
            }
            vector<struct Point> points = getComboAttackPoints(gameMap, color, data);
            for (int i = 0; i < points.size(); i++)
            {
                struct Point point = points[i];
                setColor(point, color, VOID, targetColor, score, gameMap);
                struct Point nextLastPoint = lastPoint;
                if (data.fourAttack.find(point) != data.end() || data.threeOpenAttack.find(point) != data.end())
                {
                    nextLastPoint = point;
                }
                bool value = dfsKill(gameMap, getOtherColor(color), targetColor, level - 1, score, nextLastPoint);
                if (value)
                {
                    setColor(point, VOID, color, targetColor, score, gameMap);
                    return true;
                }
                setColor(point, VOID, color, targetColor, score, gameMap);
            }
            return false;
        }
        else
        {
            if (data.fiveAttack.size() > 0)
            {
                return false;
            }
            vector<struct Point> points = getComboDefencePoints(gameMap, color, data);
            //如果没有能防的则结束
            if (points.size() == 0)
            {
                return false;
            }
            for (int i = 0; i < points.size(); i++)
            {
                struct Point point = points[i];
                setColor(point, color, VOID, targetColor, score, gameMap);
                bool value = dfsKill(gameMap, color.getOtherColor(), targetColor, level - 1, score, lastPoint);
                if (!value)
                {
                    setColor(point, VOID, color, targetColor, score, gameMap);
                    return false;
                }
                setColor(point, VOID, color, targetColor, score, gameMap);
            }
            return true;
        }
    }

    static vector<struct Point> getComboAttackPoints(GameMap *gameMap, Color color, Analyzer *data)
    {
        //如果有对方冲4，则防冲4
        if (data->fourDefence.size() > 0)
        {
            return converToVector(data.fourDefence);
        }
        //如果有对方活3，冲四
        if (data.threeDefence.size() > 0)
        {
            return new ArrayList<>(data.getFourAttack());
        }
        vector<struct Point> result;
        result.addAll(data.getFourAttack());
        result.addAll(data.getThreeOpenAttack());
        return result;
    }

    static vector<struct Point> getComboDefencePoints(GameMap *gameMap, Color color, Analyzer *data)
    {
        //如果有对方冲4，则防冲4
        if (data->fourDefence.size() > 0)
        {
            return converToVector(data.fourDefence);
        }
        //如果有对方活3，则防活3或者冲四
        if (!data.getThreeDefence().isEmpty())
        {
            // return new ArrayList<Point>(data.getFourAttack()) {{
            //     addAll(data.getThreeDefence());
            // }};
        }
        vector<struct Point> result;
        return result;
    }

    static void setColor(Point point, Color color, Color forwardColor, Color aiColor, Score *score, GameMap *gameMap)
    {
        score->setColor(point, color, forwardColor, aiColor);
        gameMap->setColor(point, color);
    }

    static vector<struct Point> converToVector(set<struct Point> *points)
    {
        vector<struct Point> result;
        set<struct Point>::iterator it;
        for (it = points->begin(); it != points->end(); it++)
        {
            result.push_back(*it);
        }
        return result;
    }

    static vector<struct Point> converToVector(set<struct Point> *points1, set<struct Point> *points2)
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
};

#endif