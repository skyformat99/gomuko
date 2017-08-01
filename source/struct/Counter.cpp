#ifndef _Counter_
#define _Counter_

class Counter
{
  public:
    int count;

    int comboCount;

    int finishStep;

    int allStep;

    int cacheExpandHit;

    int cacheComboHit;

    void clear()
    {
        count = 0;
        finishStep = 0;
        allStep = 0;
        cacheExpandHit = 0;
        cacheComboHit = 0;
        comboCount = 0;
    }
};

#endif