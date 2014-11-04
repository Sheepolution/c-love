#include "player.h"

void Player_load(Player *self) {
	self->img = love_graphics_newImage("hero.bmp");
	self->x = 100;
	self->y = 100;
	self->speed = 0.1;
}

void Player_update(Player *self) {
	self->x += self->speed;
	if (love_keyboard_isDown("a") == 1) {
		self->speed = -0.1;
	}
}

void Player_draw(Player *self) {
	love_graphics_draw(self->img,self->x,self->y);
}