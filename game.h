#pragma once

#include "birds.h"
#include "Column.h"
#include "land.h"
#include "sound.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class game:LTexture
{
public:
    struct input
    {
        enum type { QUIT, PLAY, NONE, PAUSE};
        type Type;
    };
    input UserInput;
    bird bird;
    column column;
    sound sound;
    land land;
public:
    game();

    ~game();

    bool initGraphic();

    bool isQuit() 
    {
        return quit; 
    }

    bool isLost()
    {
        return lost;
    }

    int getColumnWidth()
    {
        return column.width();
    }

    int getColumnHeight()
    {
        return column.height();
    }

    void takeInput();

    void display();

    void releaseGraphic();

    void renderScoreSmall();

    void renderScoreLarge();

    void renderBestScore();

    void renderMessage();

    void renderBackground();

    void renderBackgroundNight();

    void renderLand();

    void resume();

    void pause();

    void renderPauseTab();

    void lightTheme();

    void darkTheme();

    void nextButton();

    bool changeTheme();

    void renderGameOver();

    void renderMedal();

    void replay();

    bool checkReplay();

    void Restart();

private: 
    const double scaleNumberS = 0.6;
    short int bestScore;
};