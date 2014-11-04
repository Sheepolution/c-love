#include <SDL2/SDL.h>
#include <stdio.h>
#define love_image SDL_Texture*

void print();
void love_init(int width, int height, void *update(),void *draw());

SDL_Window *love_window = NULL;
SDL_Renderer *love_renderer = NULL;

love_image love_graphics_newImage();

void print() {

}
// void love_init(int width, int height, void *update()) {
void love_init(int width, int height, void *update(),void *draw()) {

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    love_window = SDL_CreateWindow("Hello World", 100, 100, width, height, 0);

    love_renderer = SDL_CreateRenderer(love_window, -1, SDL_RENDERER_ACCELERATED);

  	// SDL_Rect pos = {50,50,97,81};


	while (1) {
	        SDL_Event e;
	        if (SDL_PollEvent(&e)) {
	            if (e.type == SDL_QUIT) {
	                break;
	            }
	        }
	        update();


	        SDL_RenderClear(love_renderer);
	        draw();
	        SDL_RenderPresent(love_renderer);
	    }

    SDL_DestroyRenderer(love_renderer);
    SDL_DestroyWindow(love_window);

    return;
}

love_image love_graphics_newImage() {
	SDL_Texture *bitmapTex = NULL;
    SDL_Surface *bitmapSurface = NULL;
	bitmapSurface = SDL_LoadBMP("hero.bmp");
	bitmapTex = SDL_CreateTextureFromSurface(love_renderer, bitmapSurface);
	SDL_FreeSurface(bitmapSurface);
	return bitmapTex;
}

void love_graphics_draw(love_image img) {
  	SDL_Rect pos = {50,50,97,81};
    SDL_RenderCopy(love_renderer, img, NULL, &pos);
}


// #include <SDL2/SDL.h>
// #include <stdio.h>

// void print();
// void love_init(int width, int height, void *update(),void *draw());

// void print() {

// }


// // void love_init(int width, int height, void *update()) {
// void love_init(int width, int height, void *update(),void *draw()) {
// 	SDL_Window *win = NULL;
//     SDL_Renderer *renderer = NULL;
//     SDL_Texture *bitmapTex = NULL;
//     SDL_Surface *bitmapSurface = NULL;

//     SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

//     // Create an application window with the following settings:
//     win = SDL_CreateWindow("Hello World", 100, 100, width, height, 0);

//     renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

// 	bitmapSurface = SDL_LoadBMP("hero.bmp");

// 	bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);

// 	SDL_FreeSurface(bitmapSurface);

//   	SDL_Rect pos = {50,50,97,81};


// 	while (1) {
// 	        SDL_Event e;
// 	        if (SDL_PollEvent(&e)) {
// 	            if (e.type == SDL_QUIT) {
// 	                break;
// 	            }
// 	        }
// 	        update();

// 	        draw();

// 	        SDL_RenderClear(renderer);
// 	        SDL_RenderCopy(renderer, bitmapTex, NULL, &pos);
// 	        SDL_RenderPresent(renderer);
// 	    }

//     SDL_DestroyTexture(bitmapTex);
//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(win);

//     return;
// }

// // love_image love_graphics_newImage() {
// // 	SDL_Texture *bitmapSurface = SDL_LoadBMP("hero.bmp");
// // 	SDL_Surface *bitmapTex = SDL_CreateTextureFromSurface(love_renderer, bitmapSurface);
// // 	SDL_FreeSurface(bitmapSurface);
// // 	return bitmapTex;
// // }