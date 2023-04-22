#include "game.h"
#include "lib.h"
#include <time.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

const short int FPS = 60;
const short int frameDelay = 1000 / FPS;

using namespace std;

int main(int argc, char** argv)
{


    Uint32 frameStart;
    short int frameTime;
    game g;
    srand(time(0));
    bool isMenu = 0;
    bool isPause = 0;
    bool isSound = 1;
    bool isDark = 0;

    while(!g.isQuit())
    {
        frameStart = SDL_GetTicks();

        if (g.isLost())
        {
            if (isMenu) {
                g.sound.playHit();
                g.bird.render();
            }
            g.UserInput.Type = game::input::NONE;
            while(g.isLost() && !g.isQuit())
            {
                g.takeInput();
                if (isMenu == 1 && g.UserInput.Type == game::input::PLAY)
                {
                    if (g.checkReplay())
                    {
                        isMenu = 0;
                    }
                    g.UserInput.Type = game::input::NONE;
                }
                if (!isDark) g.renderBackground();
                else g.renderBackgroundNight();
                g.column.render();
                g.land.render();
                if (isMenu)
                {
                    g.bird.render();
                    g.bird.fall();
                    g.renderGameOver();
                    g.renderMedal();
                    g.renderScoreSmall();
                    g.renderBestScore();
                    g.replay();
                }
                else
                {
                    g.column.init();
                    g.bird.init(isDark); 
                    g.bird.render();
                    g.renderMessage();
                    if (g.UserInput.Type == game::input::PLAY)
                    {
                        g.Restart();
                        isMenu = 1;
                        g.UserInput.Type = game::input::NONE;
                    }
                    g.land.update();
                }
                g.display();
            }
            g.column.init();
        }
        else
        {
            g.takeInput();

            if (g.UserInput.Type == game::input::PAUSE)
            {
                isPause = abs(1-isPause);
                g.UserInput.Type = game::input::NONE;
            }

            if (isPause == 0 && g.UserInput.Type == game::input::PLAY)
            {
                if (isSound) g.sound.playBreath();
                g.bird.resetTime(); 
                g.UserInput.Type = game::input::NONE;
            }

            if (!isDark) g.renderBackground();
            else g.renderBackgroundNight();
            g.column.render();
            g.land.render();
            g.bird.render();
            g.renderScoreLarge();

            if (!isPause)
            {
                g.bird.update(g.getColumnWidth(), g.getColumnHeight());
                g.column.update();
                g.land.update();
                g.pause();
            }
            else
            {
                g.resume();
                g.renderPauseTab();
                g.renderScoreSmall();
                g.renderBestScore();
                g.replay();
                g.sound.renderSound();
                if (!isDark) g.lightTheme(); else g.darkTheme();
                g.nextButton();
                if (g.UserInput.Type == game::input::PLAY)
                {
                    if (g.checkReplay())
                    {
                        isPause = 0;
                    }
                    else if (g.sound.soundIcon())
                    {
                        isSound = abs(1-isSound);
                    }
                    else if (g.changeTheme())
                    {
                        isDark = abs(1-isDark);
                        g.bird.init(isDark);
                    }
                    g.UserInput.Type = game::input::NONE;
                }
            }
            g.display();
        }

        //Limit FPS
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    return 0;
}