typedef struct {
	Animation anim;
	float x,y,speed;
	int w,h,dir;
	
} Player;

#include "player.h"
float test;
float animCounter;
void Player_load(Player *self) {
	Animation_new(&self->anim,"player.bmp",23,27);
	self->anim.speed = 5;
	self->anim.start = 4;
	self->anim.stop = 7;
	self->x = 100;
	self->y = 192;
	self->speed = 300;
	self->dir = 1;
}

void Player_update(Player *self, float dt) {
	test += 0.01;
	if (love_keyboard_isDown("right")) {
		self->dir = 1;
		self->x += self->speed * dt;
		self->anim.start = 4;
		self->anim.stop = 7;
		self->anim.speed = 8;

	}
	else if (love_keyboard_isDown("left")) {
		self->dir = -1;
		self->x -= self->speed * dt;
		self->anim.start = 4;
		self->anim.stop = 7;
		self->anim.speed = 8;
	}
	else {
		self->anim.start = 0;
		self->anim.stop = 3;
		self->anim.speed = 5;
	}
	Animation_update(&self->anim, dt);
}

void Player_draw(Player *self) {
	Animation_drawEx(&self->anim,self->x,self->y,0,4*self->dir,4,11,13);
}