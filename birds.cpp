#include "birds.h"
#include <stdio.h>
#include <iostream>
using namespace std;

bool bird::init(bool isDark)
{
    string bird_path = "data/image/red_bird.png";
    if (isDark) bird_path = "data/image/black_bird.png";
    if (saved_path == bird_path)
    {
        pos.getPos(75, SCREEN_HEIGHT / 2 - 10);
        ahead = 0;
        angle = 0;
    }
    if (isNULL() || saved_path != bird_path)
    {
        saved_path = bird_path;
        if ( Load(bird_path.c_str() , 1) )
        {
            //angle = 0;
            //time = -1;
            return true;
        }
        else
        {
            return false;
        }

    }
    return false;
}

void bird::Free()
{
    free();
}

void bird::render()
{
    Render(pos.x, pos.y, angle);
}

void bird::fall() 
{
    if (lost && pos.y < SCREEN_HEIGHT - LAND_HEIGHT - BIRD_HEIGHT - 5)
    {
        if (time == 0)
        {
            x0 = pos.y;
            angle = -25;
        }
        else if (angle < 70 && time > 30)
        {
            angle += 3;
        }

        if (time >= 0)
        {
            pos.y = x0 + time * time * 0.18 - 7.3 * time;
            time++;
        }
    }
    else return;
}

void bird::update(short int columnWidth, short int columnHeight)
{
    if (!lost)
    {
        if (time == 0)
        {
            x0 = pos.y;
            angle = -25;
        }
        else if (angle < 70 && time > 30)
        {
            angle += 3;
        }

        if (time >= 0)
        {
            pos.y = x0 + time * time * 0.18 - 7.3 * time;
            time++;
        }

        if ( (pos.x + getWidth() > posColumn[ahead].x + 5) && (pos.x + 5 < posColumn[ahead].x + columnWidth) &&
             (pos.y + 5 < posColumn[ahead].y + columnHeight || pos.y  + getHeight() > posColumn[ahead].y + columnHeight + COLUMN_SPACE + 5) )
        {
            lost = true;
        }
        else if (pos.x > posColumn[ahead].x + columnWidth )
        {
            ahead = ( ahead + 1 ) % TOTAL_COLUMN;
            score++;
        }

        if ( pos.y > SCREEN_HEIGHT - LAND_HEIGHT -  BIRD_HEIGHT - 5 || pos.y < - 10 )
        {
            lost = true;
        }
    }
}