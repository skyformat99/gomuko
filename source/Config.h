#ifndef _Config_
#define _Config_

class Config
{
  public:
    Config();

    static const int MAX_VALUE = 1000000;
    static const int MIN_VALUE = -1000000;

    static const int size = 15;

    int searchDeep;

    int comboDeep;

    bool debug;
};

#endif