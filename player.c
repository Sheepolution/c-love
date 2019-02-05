#include "player.h"

void Player_new(Player *self) {
	Animation_new(&self -> anim,"player.bmp",23,27);
	self -> anim.speed = 5;
	self -> anim.start = 4;
	self -> anim.stop = 7;
	self -> x = 100;\
	self -> y = 192;
	self -> speed = 300;
	self -> dir = 1;
	love_point_new(&self -> velocity,0,0);
}

void Player_update(Player *self, float dt) {
	if (love_keyboard_isDown("right")) {
		self -> dir = 1;
		self -> x += self -> speed * dt;
		Animation_set(&self -> anim,4,7,8);
	}
	else if (love_keyboard_isDown("left")) {
		self -> dir = -1;
		self -> x -= self -> speed * dt;
		Animation_set(&self -> anim,4,7,8);
	}
	else {
		Animation_set(&self -> anim,0,3,5);
	}
	Animation_update(&self -> anim, dt);

	// if (love_keyboard_isDown("up")) {
	// 	self -> y -= 100 * dt;
	// }

	if (love_keyboard_isPressed("up")) {
		self -> velocity.y = -1000;
	}

	self -> velocity.y += 4000 * dt;

	self -> y += self -> velocity.y * dt;

	if (self -> y > 192) {
		self -> y = 192;
	}
}

void Player_draw(Player *self) {
	Animation_drawEx(&self -> anim,self -> x,self -> y,0,4*self -> dir,4,11,13);
}


// void Player_shoot(Player *self) {

// }