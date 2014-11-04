#include <SDL2/SDL.h>
#include <math.h>
#include <stdarg.h>
#include "love.h"

// void love_init(int width, int height, void *update()) {
void love_init(int width, int height) {

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    love_window = SDL_CreateWindow("_float", 400, 100, width, height, 0);

    love_renderer = SDL_CreateRenderer(love_window, -1, SDL_RENDERER_ACCELERATED);

    love_load();
	printf("Oke en nu... \n");

    int gameRunning = 1;
	while (gameRunning == 1) {
	        SDL_Event e;
	        if (SDL_PollEvent(&e)) {
	            if (e.type == SDL_QUIT) {
	                break;
	            }
	            if (e.type == SDL_KEYDOWN) {
	            	// printf("%i \n",e.key.keysym.sym);
	            	switch (e.key.keysym.sym) {
	            		case SDLK_a :
	            		love_keys.a = 1;
	            		break;
	            		case SDLK_b :
	            		love_keys.b = 1;
	            		break;
	            		case SDLK_c :
	            		love_keys.c = 1;
	            		break;
	            	}
	         	}
	        }
	        love_update();


	        SDL_RenderClear(love_renderer);
	        love_draw();
	        SDL_RenderPresent(love_renderer);
	    }

    SDL_DestroyRenderer(love_renderer);
    SDL_DestroyWindow(love_window);

    return;
}

love_image love_graphics_newImage(char *url) {
	SDL_Texture *bitmapTex = NULL;
    SDL_Surface *bitmapSurface = NULL;
	bitmapSurface = SDL_LoadBMP(url);
	bitmapTex = SDL_CreateTextureFromSurface(love_renderer, bitmapSurface);
	SDL_FreeSurface(bitmapSurface);
	return bitmapTex;
}

void love_graphics_draw(love_image img,float _x, float _y) {
	int w,h;
	SDL_QueryTexture(img,NULL,NULL,&w,&h);
  	SDL_Rect pos = {_x,_y,w,h};
  	// SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL;
    SDL_RenderCopy(love_renderer, img, NULL, &pos);
}

void love_graphics_drawEx(love_image img,float _x, float _y, double _r, float _sx, float _sy, float _ox, float _oy) {
	int w,h;
	SDL_QueryTexture(img,NULL,NULL,&w,&h);
	w*=_sx;
	h*=_sy;
  	SDL_Rect pos = {_x,_y,w,h};
  	SDL_Point point = {_ox,_oy};
  	SDL_RendererFlip flip = SDL_FLIP_NONE;
  	// SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL;
    SDL_RenderCopyEx(love_renderer, img, NULL, &pos,_r*(180/M_PI),&point,flip);
}

int love_keyboard_isDown(char *str) {
	if (str == "a") {
		return love_keys.a;
	}
	else if (str == "b") {
		return love_keys.b;
	}
	else if (str == "c") {
		return love_keys.c;
	}
}