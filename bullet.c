#include "bullet.h"

void Bullet_new(Bullet *self,int _dir, float _speed) {
	self -> dir = _dir;
	self -> speed = _speed;
}

void Bullet_update(Bullet *self, float dt) {
	self -> x *= self -> speed * self -> dir * dt;
}

void Bullet_draw(Bullet *self) {
	love_graphics_drawEx(self -> img,self -> x,self -> y,0,self -> dir,1,50,40);
}


// void Player_shoot(Player *self) {

// }