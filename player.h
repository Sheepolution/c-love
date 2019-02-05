typedef struct {
	Animation anim;
	float x,y,speed;
	int w,h,dir;
	love_point velocity;
} Player;

void Player_new(Player *self);
void Player_update(Player *self, float dt);
void Player_draw(Player *self);