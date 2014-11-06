#include <SDL2/SDL.h>
#include <math.h>
#include <stdarg.h>
#include "love.h"

// void love_init(int width, int height, void *update()) {
void love_init(int width, int height) {

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    love_window = SDL_CreateWindow("_float", 50, 50, width, height, 0);

    love_renderer = SDL_CreateRenderer(love_window, -1, SDL_RENDERER_ACCELERATED);
    love_load();
	printf("Oke en nu... \n");

	float deltaTime;
	int current, last;
	current = SDL_GetTicks();

    int gameRunning = 1;
	while (gameRunning == 1) {
	        SDL_Event e;
	        if (SDL_PollEvent(&e)) {
	            if (e.type == SDL_QUIT) {
	                break;
	            }
	            if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
	            	love_setKey(e);
	         	}
	        }

	        // current = SDL_GetTicks();
	        last = current;
	        current = SDL_GetTicks();
	        deltaTime = (double) (current - last) / 1000;

	        love_update(deltaTime);


	        SDL_RenderClear(love_renderer);
	        love_draw();
	        SDL_RenderPresent(love_renderer);
	    }

    SDL_DestroyRenderer(love_renderer);
    SDL_DestroyWindow(love_window);

    return;
}

//love_graphics

love_image love_graphics_newImage(char *url) {
	love_image img;
	SDL_Texture *bitmapTex = NULL;
    SDL_Surface *bitmapSurface = NULL;
	bitmapSurface = SDL_LoadBMP(url);
	bitmapTex = SDL_CreateTextureFromSurface(love_renderer, bitmapSurface);
	SDL_FreeSurface(bitmapSurface);

	img.texture = bitmapTex;
	SDL_QueryTexture(bitmapTex,NULL,NULL,&img.width,&img.height);

	return img;
}

int love_image_getWidth(love_image img) {
	return img.width;
}

int love_image_getHeight(love_image img) {
	return img.height;
}

love_quad love_graphics_newQuad(int x, int y, int w, int h) {
	love_quad quad;
	quad.x = x;
	quad.y = y;
	quad.width = w;
	quad.height = h;
	return quad;
}

void love_graphics_draw(love_image img,float _x, float _y) {
  	SDL_Rect pos = {_x,_y,img.width,img.height};
  	// SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL;
    SDL_RenderCopy(love_renderer, img.texture, NULL, &pos);
}

void love_graphics_drawq(love_image img, love_quad quad, float _x, float _y) {
  	SDL_Rect pos = {_x,_y,quad.width,quad.height};
  	SDL_Rect qd = {quad.x,quad.y,quad.width,quad.height};
  	// SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL;
    SDL_RenderCopy(love_renderer, img.texture, &qd, &pos);
}

void love_graphics_drawEx(love_image img, float _x, float _y, double _r, float _sx, float _sy, float _ox, float _oy) {
  	SDL_Rect pos = {_x,_y,img.width*_sx,img.height*_sy};
  	SDL_Point point = {_ox*_sx,_oy*_sy};
  	SDL_RendererFlip flip = SDL_FLIP_NONE;
  	// SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL;
    SDL_RenderCopyEx(love_renderer, img.texture, NULL, &pos,_r*(180/M_PI),&point,flip);
}

void love_graphics_drawqEx(love_image img, love_quad quad, float _x, float _y, double _r, float _sx, float _sy, float _ox, float _oy) {
  	float _osx, _osy;
  	_osx = _sx;
  	_osy = _sy;
  	_sx = abs(_sx);
  	_sy = abs(_sy);
  	SDL_Rect pos = {_x,_y,quad.width*_sx,quad.height*_sy};
  	SDL_Rect qd = {quad.x,quad.y,quad.width,quad.height};
  	SDL_Point point = {_ox*_sx,_oy*_sy};
  	SDL_RendererFlip flip;
  	if (_osx < 0 && _osy < 0) { 
  		flip = SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL;
  	}
  	else if (_osx < 0) {
  		flip = SDL_FLIP_HORIZONTAL;
  	}
  	else if (_osy < 0) {
  		flip = SDL_FLIP_VERTICAL;
  	}
  	// SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL;
    SDL_RenderCopyEx(love_renderer, img.texture, &qd, &pos,_r*(180/M_PI),&point,flip);
}

//love_keyboard

void love_setKey(SDL_Event e) {
	int key = e.key.keysym.sym;
	switch (key) {
		case SDLK_a : love_keyState(e,&love_keys.a);
		break;
		case SDLK_b : love_keyState(e,&love_keys.b);
		break;
		case SDLK_c : love_keyState(e,&love_keys.c);
		break;
		case SDLK_d : love_keyState(e,&love_keys.d);
		break;
		case SDLK_e : love_keyState(e,&love_keys.e);
		break;
		case SDLK_f : love_keyState(e,&love_keys.f);
		break;
		case SDLK_g : love_keyState(e,&love_keys.g);
		break;
		case SDLK_h : love_keyState(e,&love_keys.h);
		break;
		case SDLK_i : love_keyState(e,&love_keys.i);
		break;
		case SDLK_j : love_keyState(e,&love_keys.j);
		break;
		case SDLK_k : love_keyState(e,&love_keys.k);
		break;
		case SDLK_l : love_keyState(e,&love_keys.l);
		break;
		case SDLK_m : love_keyState(e,&love_keys.m);
		break;
		case SDLK_n : love_keyState(e,&love_keys.n);
		break;
		case SDLK_o : love_keyState(e,&love_keys.o);
		break;
		case SDLK_p : love_keyState(e,&love_keys.p);
		break;
		case SDLK_q : love_keyState(e,&love_keys.q);
		break;
		case SDLK_r : love_keyState(e,&love_keys.r);
		break;
		case SDLK_s : love_keyState(e,&love_keys.s);
		break;
		case SDLK_t : love_keyState(e,&love_keys.t);
		break;
		case SDLK_u : love_keyState(e,&love_keys.u);
		break;
		case SDLK_v : love_keyState(e,&love_keys.v);
		break;
		case SDLK_w : love_keyState(e,&love_keys.w);
		break;
		case SDLK_x : love_keyState(e,&love_keys.x);
		break;
		case SDLK_z : love_keyState(e,&love_keys.z);
		break;
		case SDLK_LSHIFT : love_keyState(e,&love_keys.lshift);
		break;
		case SDLK_LCTRL : love_keyState(e,&love_keys.lctrl);
		break;
		case SDLK_SPACE : love_keyState(e,&love_keys.space);
		break;
		case SDLK_LEFT : love_keyState(e,&love_keys.left);
		break;
		case SDLK_RIGHT : love_keyState(e,&love_keys.right);
		break;
		case SDLK_UP : love_keyState(e,&love_keys.up);
		break;
		case SDLK_DOWN : love_keyState(e,&love_keys.down);
		break;
	}
}

void love_keyState(SDL_Event e,int *key) {
	if (e.type == SDL_KEYDOWN) {
		if (*key != 1 && *key !=2) {
			*key = 1;
		}
		else {
			*key = 2;
		}
	}
	else if (e.type == SDL_KEYUP) {
		if (*key == 1 || *key == 2) {
			*key = 3;
		}
		else {
			*key = 0;
		}
	}
}

int love_keyboard_isDown(char *str) {
	if (str == "a") {
		return love_keys.a==1 || love_keys.a==2;
	}
	else if (str == "b") {
		return love_keys.b==1 || love_keys.b==2;
	}
	else if (str == "c") {
		return love_keys.c==1 || love_keys.c==2;
	}
	else if (str == "d") {
		return love_keys.d==1 || love_keys.d==2;
	}
	else if (str == "e") {
		return love_keys.e==1 || love_keys.e==2;
	}
	else if (str == "f") {
		return love_keys.f==1 || love_keys.f==2;
	}
	else if (str == "g") {
		return love_keys.g==1 || love_keys.g==2;
	}
	else if (str == "h") {
		return love_keys.h==1 || love_keys.h==2;
	}
	else if (str == "i") {
		return love_keys.i==1 || love_keys.i==2;
	}
	else if (str == "j") {
		return love_keys.j==1 || love_keys.j==2;
	}
	else if (str == "k") {
		return love_keys.k==1 || love_keys.k==2;
	}
	else if (str == "l") {
		return love_keys.l==1 || love_keys.l==2;
	}
	else if (str == "m") {
		return love_keys.m==1 || love_keys.m==2;
	}
	else if (str == "n") {
		return love_keys.n==1 || love_keys.n==2;
	}
	else if (str == "o") {
		return love_keys.o==1 || love_keys.o==2;
	}
	else if (str == "p") {
		return love_keys.p==1 || love_keys.p==2;
	}
	else if (str == "q") {
		return love_keys.q==1 || love_keys.q==2;
	}
	else if (str == "r") {
		return love_keys.r==1 || love_keys.r==2;
	}
	else if (str == "s") {
		return love_keys.s==1 || love_keys.s==2;
	}
	else if (str == "t") {
		return love_keys.t==1 || love_keys.t==2;
	}
	else if (str == "u") {
		return love_keys.u==1 || love_keys.u==2;
	}
	else if (str == "v") {
		return love_keys.v==1 || love_keys.v==2;
	}
	else if (str == "w") {
		return love_keys.w==1 || love_keys.w==2;
	}
	else if (str == "x") {
		return love_keys.x==1 || love_keys.x==2;
	}
	else if (str == "y") {
		return love_keys.y==1 || love_keys.y==2;
	}
	else if (str == "z") {
		return love_keys.z==1 || love_keys.z==2;
	}
	else if (str == "left") {
		return love_keys.left==1 || love_keys.left==2;
	}
	else if (str == "right") {
		return love_keys.right==1 || love_keys.right==2;
	}
	else if (str == "up") {
		return love_keys.up==1 || love_keys.up==2;
	}
	else if (str == "down") {
		return love_keys.down==1 || love_keys.down==2;
	}
	else if (str == "space") {
		return love_keys.space==1 || love_keys.space==2;
	}
	else if (str == "shift") {
		return love_keys.lshift==1 || love_keys.lshift==2;
	}
	else if (str == "lctrl") {
		return love_keys.lctrl==1 || love_keys.lctrl==2;
	}
}
