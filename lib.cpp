#include "game.h"
#include <iostream>

bool LTexture::quit = false;
SDL_Window* LTexture::gWindow = NULL;
SDL_Renderer* LTexture::gRenderer = NULL;
SDL_Event LTexture::e;
short int LTexture::score = 0;
bool LTexture::lost = true;

LTexture::LTexture()
{
	Texture = NULL;
}

void LTexture::free()  // đóng kết cấu
{
	//Free texture if it exists
	if( Texture != NULL )
	{
		SDL_DestroyTexture( Texture );
		Texture = NULL;
		tWidth = 0;
		tHeight = 0;
	}
}

short int LTexture::getWidth()  // lấy chiều rộng kết cấu
{
	return tWidth;
}

short int LTexture::getHeight()  // lấy chiều dài kết cấu 
{
	return tHeight;
}

void LTexture::Render(short int x, short int y, short int angle, SDL_Rect* clip, SDL_RendererFlip flip)  // hiện thị ảnh lên màn hình
{
	//Set rendering space and render to screen
	SDL_Rect Rec_Render = { x, y, tWidth, tHeight };

    if( clip != NULL )
	{
		Rec_Render.w = clip->w ;  // gán chiều rộng ảnh tại vị trí truy cập
		Rec_Render.h = clip->h ;  // gán chiều dài ảnh tại vị trí truy cập
	}

	//Render to screen
    SDL_RenderCopyEx( gRenderer, Texture, clip, &Rec_Render, angle, NULL, flip ); // sao chép ảnh và cho nó xuất hiện tại vị trí mới
}

bool LTexture::Load(string path, double scale) // load ảnh, biến scale nhằm thay đổi tỉ lệ ảnh 
{
	//Get rid of preexisting texture
	free();

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		cout<<"Unable to load image!"<<endl;
		IMG_GetError();
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0x00, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        Texture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( Texture == NULL )
		{
			cout<< "Unable to create texture!"<<endl;
			SDL_GetError();
		}
		else
		{
			//Get image dimensions
			tWidth = (loadedSurface->w) * scale;
			tHeight = (loadedSurface->h) * scale;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	//Return success
	return Texture != NULL;

}

bool LTexture::isNULL()// check kích thức ảnh 
{
    if (Texture == NULL) return true;
    return false;
}

void position::getPos(const short int x, const short int y) // vị trí vật 
{
    this->x = x;
    this->y = y;
}