#pragma once

#include "lib.h"
#include "Column.h"
using namespace std;

class bird:LTexture
{
private:
    short int angle, time, x0;
    position pos;
    short int ahead = 0;
public:
    bool init(bool isDark);

    void render();

    void Free();

    void resetTime() { time = 0;}

    void fall();

    void update(short int columnWidth, short int columnHeight);

    string saved_path = "";
};