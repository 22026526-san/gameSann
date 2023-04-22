#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include<iostream>
using namespace std;

class position  // vị trí
{
public:
    short int x, y, angle, state;
    void getPos(const short int x, const short int y);
};

class LTexture  //kết cấu của các đối tượng
{
public:
    LTexture();

    ~LTexture() {}

    bool isNULL();

    void free();

    bool Load(string path, double scale = 1);

    void Render(short int x, short int y, short int angle = 0, SDL_Rect* clip = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

    short int getWidth();
    short int getHeight();

public:
    SDL_Texture* Texture;

    short int tWidth;
    short int tHeight;

public:
    static SDL_Window* gWindow;
    static SDL_Renderer* gRenderer;
    static SDL_Event e;
    static bool quit;
    static bool lost;
    static short int score;

    static const short int SCREEN_WIDTH = 350;
    static const short int SCREEN_HEIGHT = 625;

    static const short int COLUMN_SPACE = 160;
    static const short int TOTAL_COLUMN = 4;
    static const short int COLUMN_DISTANCE = 220;
    static const short int LAND_HEIGHT = 140;
    static const short int BIRD_WIDTH = 50;
    static const short int BIRD_HEIGHT = 35;
};