#include "Column.h"
#include <stdio.h>


vector<position> posColumn;

bool column::init()
{
    posColumn.clear();
    for (signed char i = 0; i < TOTAL_COLUMN; i++)
    {
        position k;
        k.getPos(SCREEN_WIDTH + i * COLUMN_DISTANCE + 350, (rand() % (randMax - randMin + 1)) + randMin);
        posColumn.push_back(k);
    }
    if (isNULL())
    {
        if (Load( "data/image/column.png", 1 ))
        {
            return true;
        }
    }
    return false;
}

void column::Free()
{
    free();
}

void column::render()
{
    for (signed char i = 0; i < TOTAL_COLUMN; i++)
    {
        if (posColumn[i].x <= SCREEN_WIDTH && posColumn[i].x > -getWidth())
        {
            Render(posColumn[i].x, posColumn[i].y);
        }
        Render(posColumn[i].x, posColumn[i].y + getHeight() + COLUMN_SPACE, 180);
    }
}

void column::update()
{
    if (!lost)
    {
        for (signed char i = 0; i < TOTAL_COLUMN; i++)
        {
            if (posColumn[i].x < - getWidth())
            {
                posColumn[i].y = (rand() % (randMax - randMin + 1)) + randMin;
                posColumn[i].x = posColumn[(i + TOTAL_COLUMN - 1) % TOTAL_COLUMN].x + COLUMN_DISTANCE;
            }
            else
            {
                posColumn[i].x -= 3;
            }
        }
    }
}