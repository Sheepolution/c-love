typedef struct {
	love_image img;
	float x,y,speed;
	int w,h;
} Player;

void Player_load(Player *self);
void Player_update(Player *self);
void Player_draw(Player *self);