#include <SDL2/SDL.h>
#include <math.h>
#include <stdarg.h>
#include "love.h"

// void love_init(int width, int height, void *update()) {
void love_init(int width, int height) {

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    love_window = SDL_CreateWindow("_float", 600, 300, width, height, 0);

    love_renderer = SDL_CreateRenderer(love_window, -1, SDL_RENDERER_ACCELERATED);
    love_load();

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
	            	love_keyboard__setKey(e);
	         	}
	        }

	        // current = SDL_GetTicks();
	        last = current;
	        current = SDL_GetTicks();
	        deltaTime = (double) (current - last) / 1000;

	        love_update(deltaTime);

	        love_keyboard__updateKeys();

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

void love_keyboard__keyState(SDL_Event e,int *key) {

	if (e.type == SDL_KEYDOWN) {
		if (*key != 3) {
			*key = 2;
		}
	}
	else if (e.type == SDL_KEYUP) {
		*key = 1;
	}
}

void love_keyboard__update(int *key) {
	if (*key == 2) {
		*key = 3;
	}
	if (*key == 1) {
		*key = 0;
	}
}

void love_keyboard__setKey(SDL_Event e) {
	SDL_Keycode key = e.key.keysym.sym;
	switch (key) {
		case SDLK_a : love_keyboard__keyState(e,&love_keys.a); break;
		case SDLK_b : love_keyboard__keyState(e,&love_keys.b); break;
		case SDLK_c : love_keyboard__keyState(e,&love_keys.c); break;
		case SDLK_d : love_keyboard__keyState(e,&love_keys.d); break;
		case SDLK_e : love_keyboard__keyState(e,&love_keys.e); break;
		case SDLK_f : love_keyboard__keyState(e,&love_keys.f); break;
		case SDLK_g : love_keyboard__keyState(e,&love_keys.g); break;
		case SDLK_h : love_keyboard__keyState(e,&love_keys.h); break;
		case SDLK_i : love_keyboard__keyState(e,&love_keys.i); break;
		case SDLK_j : love_keyboard__keyState(e,&love_keys.j); break;
		case SDLK_k : love_keyboard__keyState(e,&love_keys.k); break;
		case SDLK_l : love_keyboard__keyState(e,&love_keys.l); break;
		case SDLK_m : love_keyboard__keyState(e,&love_keys.m); break;
		case SDLK_n : love_keyboard__keyState(e,&love_keys.n); break;
		case SDLK_o : love_keyboard__keyState(e,&love_keys.o); break;
		case SDLK_p : love_keyboard__keyState(e,&love_keys.p); break;
		case SDLK_q : love_keyboard__keyState(e,&love_keys.q); break;
		case SDLK_r : love_keyboard__keyState(e,&love_keys.r); break;
		case SDLK_s : love_keyboard__keyState(e,&love_keys.s); break;
		case SDLK_t : love_keyboard__keyState(e,&love_keys.t); break;
		case SDLK_u : love_keyboard__keyState(e,&love_keys.u); break;
		case SDLK_v : love_keyboard__keyState(e,&love_keys.v); break;
		case SDLK_w : love_keyboard__keyState(e,&love_keys.w); break;
		case SDLK_x : love_keyboard__keyState(e,&love_keys.x); break;
		case SDLK_y : love_keyboard__keyState(e,&love_keys.y); break;
		case SDLK_z : love_keyboard__keyState(e,&love_keys.z); break;
		case SDLK_UP : love_keyboard__keyState(e,&love_keys.up); break;
		case SDLK_RIGHT : love_keyboard__keyState(e,&love_keys.right); break;
		case SDLK_DOWN : love_keyboard__keyState(e,&love_keys.down); break;
		case SDLK_LEFT : love_keyboard__keyState(e,&love_keys.left); break;
	}
}

void love_keyboard__updateKeys() {
	love_keyboard__update( &love_keys.a);
	love_keyboard__update( &love_keys.b);
	love_keyboard__update( &love_keys.c);
	love_keyboard__update( &love_keys.d);
	love_keyboard__update( &love_keys.e);
	love_keyboard__update( &love_keys.f);
	love_keyboard__update( &love_keys.g);
	love_keyboard__update( &love_keys.h);
	love_keyboard__update( &love_keys.i);
	love_keyboard__update( &love_keys.j);
	love_keyboard__update( &love_keys.k);
	love_keyboard__update( &love_keys.l);
	love_keyboard__update( &love_keys.m);
	love_keyboard__update( &love_keys.n);
	love_keyboard__update( &love_keys.o);
	love_keyboard__update( &love_keys.p);
	love_keyboard__update( &love_keys.q);
	love_keyboard__update( &love_keys.r);
	love_keyboard__update( &love_keys.s);
	love_keyboard__update( &love_keys.t);
	love_keyboard__update( &love_keys.u);
	love_keyboard__update( &love_keys.v);
	love_keyboard__update( &love_keys.w);
	love_keyboard__update( &love_keys.x);
	love_keyboard__update( &love_keys.y);
	love_keyboard__update( &love_keys.z);
	love_keyboard__update( &love_keys.left);
	love_keyboard__update( &love_keys.right);
	love_keyboard__update( &love_keys.up);
	love_keyboard__update( &love_keys.down);
	love_keyboard__update( &love_keys.space);
	love_keyboard__update( &love_keys.lshift);
	love_keyboard__update( &love_keys.lctrl);
}

int love_keyboard_isDown(char *key) {
	if (key == "a") { return love_keys.a >= 2 ; }
	else if (key == "b") { return love_keys.b >= 2 ; }
	else if (key == "c") { return love_keys.c >= 2 ; }
	else if (key == "d") { return love_keys.d >= 2 ; }
	else if (key == "e") { return love_keys.e >= 2 ; }
	else if (key == "f") { return love_keys.f >= 2 ; }
	else if (key == "g") { return love_keys.g >= 2 ; }
	else if (key == "h") { return love_keys.h >= 2 ; }
	else if (key == "i") { return love_keys.i >= 2 ; }
	else if (key == "j") { return love_keys.j >= 2 ; }
	else if (key == "k") { return love_keys.k >= 2 ; }
	else if (key == "l") { return love_keys.l >= 2 ; }
	else if (key == "m") { return love_keys.m >= 2 ; }
	else if (key == "n") { return love_keys.n >= 2 ; }
	else if (key == "o") { return love_keys.o >= 2 ; }
	else if (key == "p") { return love_keys.p >= 2 ; }
	else if (key == "q") { return love_keys.q >= 2 ; }
	else if (key == "r") { return love_keys.r >= 2 ; }
	else if (key == "s") { return love_keys.s >= 2 ; }
	else if (key == "t") { return love_keys.t >= 2 ; }
	else if (key == "u") { return love_keys.u >= 2 ; }
	else if (key == "v") { return love_keys.v >= 2 ; }
	else if (key == "w") { return love_keys.w >= 2 ; }
	else if (key == "x") { return love_keys.x >= 2 ; }
	else if (key == "y") { return love_keys.y >= 2 ; }
	else if (key == "z") { return love_keys.z >= 2 ; }
	else if (key == "left") { return love_keys.left >= 2 ; }
	else if (key == "right") { return love_keys.right >= 2 ; }
	else if (key == "up") { return love_keys.up >= 2 ; }
	else if (key == "down") { return love_keys.down >= 2 ; }
	else if (key == "space") { return love_keys.space >= 2 ; }
	else if (key == "shift") { return love_keys.lshift >= 2 ; }
	else if (key == "lctrl") { return love_keys.lctrl >= 2 ; }
}

int love_keyboard_isPressed(char *key) {
	if (key == "a") { return love_keys.a==2;}
	else if (key == "b") { return love_keys.b==2;}
	else if (key == "c") { return love_keys.c==2;}
	else if (key == "d") { return love_keys.d==2;}
	else if (key == "e") { return love_keys.e==2;}
	else if (key == "f") { return love_keys.f==2;}
	else if (key == "g") { return love_keys.g==2;}
	else if (key == "h") { return love_keys.h==2;}
	else if (key == "i") { return love_keys.i==2;}
	else if (key == "j") { return love_keys.j==2;}
	else if (key == "k") { return love_keys.k==2;}
	else if (key == "l") { return love_keys.l==2;}
	else if (key == "m") { return love_keys.m==2;}
	else if (key == "n") { return love_keys.n==2;}
	else if (key == "o") { return love_keys.o==2;}
	else if (key == "p") { return love_keys.p==2;}
	else if (key == "q") { return love_keys.q==2;}
	else if (key == "r") { return love_keys.r==2;}
	else if (key == "s") { return love_keys.s==2;}
	else if (key == "t") { return love_keys.t==2;}
	else if (key == "u") { return love_keys.u==2;}
	else if (key == "v") { return love_keys.v==2;}
	else if (key == "w") { return love_keys.w==2;}
	else if (key == "x") { return love_keys.x==2;}
	else if (key == "y") { return love_keys.y==2;}
	else if (key == "z") { return love_keys.z==2;}
	else if (key == "left") { return love_keys.left==2;}
	else if (key == "right") { return love_keys.right==2;}
	else if (key == "up") { return love_keys.up==2;}
	else if (key == "down") { return love_keys.down==2;}
	else if (key == "space") { return love_keys.space==2;}
	else if (key == "shift") { return love_keys.lshift==2;}
	else if (key == "lctrl") { return love_keys.lctrl==2;}
}

//Point
////////////////

void love_point_new(love_point *self, float _x, float _y) {
	self -> x = _x;
	self -> y = _y;
}


