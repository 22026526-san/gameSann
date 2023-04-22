#include "sound.h"
#include <stdio.h>
#include <iostream>
#include <string>

bool sound::init() // load âm thanh, hiển thị
{
    string breath_path = "data/sound/sound_breath.wav";
    string hit_path = "data/sound/sound_bonk.wav";
    string soundIcon_path = "data/image/sound.png";

    bool success = true;

    if (SDL_Init(SDL_INIT_AUDIO) < 0)
    {
        cout<<"SDL could not initialize!"<<endl;
        SDL_GetError();
        success = false;
    }
    else
    {
        if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            cout<<"SDL_mixer could not initialize!"<<endl;
            Mix_GetError();
            success = false;
        }

        breath = Mix_LoadWAV( breath_path.c_str() );
        if ( breath == NULL )
        {
            cout<<"Failed to load sound!"<<endl;
            Mix_GetError();
            success = false;
        }

        hit = Mix_LoadWAV( hit_path.c_str() );
        if (hit == NULL)
        {
            cout<<"Failed to load chord!"<<endl;
            Mix_GetError();
            success = false;
        }

        if (!Load(soundIcon_path))
        {
            return false;
        }

        Active.x = 0; Active.y = 0; Active.w = getWidth(); Active.h = getHeight() / 2;
        Mute.x = 0; Mute.y = getHeight() / 2; Mute.w = getWidth(); Mute.h = getHeight() / 2;
        playing = true;
    }
    return success;
}

void sound::Free()  // tắt âm thanh
{
    free();

    Mix_FreeChunk(breath);
    breath = NULL;
    Mix_FreeChunk(hit);
    hit = NULL;

    Mix_Quit();
}

void sound::playBreath() // play music
{
    if (playing)
    {
        Mix_PlayChannel( -1, breath, 0 );
    }
}

void sound::playHit()  // play music 
{
    if (playing)
    {
        Mix_PlayChannel(-1, hit, 0);
    }
}

void sound::renderSound() // trạng thái âm
{
    if (playing)
    {
        Render(POS_X, POS_Y, 0, &Active);
    }
    else
    {
        Render(POS_X, POS_Y, 0, &Mute);
    }
}

bool sound::soundIcon() //trạng thái nút
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (x > POS_X && x < POS_X + getWidth() &&
        y > POS_Y && y < POS_Y + getHeight())
    {
        playing = !playing;
        return true;
    }
    return false;
}