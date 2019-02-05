typedef struct {
	float x,y,speed;
	int dir;
	love_image img;
} Bullet;

void Bullet_new(Bullet *self, int dir, float speed);

void Bullet_update(Bullet *self, float dt);

void Bullet_draw(Bullet *self);