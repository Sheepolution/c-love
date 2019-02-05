typedef struct {
	SDL_Texture* texture;
	char *blendmode;
	int width, height;
} love_image;

typedef struct {
	int x,y,width,height;
} love_quad;

#define true 1
#define false 0

void love_init(int width, int height);
void love_load(void);
void love_update(float dt);
void love_draw(void);
void love_keypressed(char *key);
void love_keyreleased(char *key);

SDL_Window *love_window = NULL;
SDL_Renderer *love_renderer = NULL;


void love_init(int width, int height);

void love_graphics_draw(love_image img,float _x, float _y);
void love_graphics_drawq(love_image img, love_quad quad, float _x, float _y);

void love_graphics_drawEx(love_image img,float _x, float _y, double _r, float _sx, float _sy, float _ox, float _oy);
void love_graphics_drawqEx(love_image img, love_quad quad, float _x, float _y, double _r, float _sx, float _sy, float _ox, float _oy);


love_image love_graphics_newImage(char *url);
int love_image_getWidth(love_image img);
int love_image_getHeight(love_image img);

love_quad love_graphics_newQuad(int x, int y, int w, int h);

struct love_keys_struct {
	int a,b,c,d,e,f,g,h,j,i,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,lctrl,lshift,space,left,right,up,down;
};

struct love_keys_struct love_keys;

void love_keyboard__setKey(SDL_Event e);
void love_keyboard__keyState(SDL_Event e,int *key);
void love_keyboard__updateKeys();
void love_keyboard__update(int *key);
int love_keyboard_isDown(char *key);
int love_keyboard_isPressed(char *key);


//Point

typedef struct {
	float x;
	float y;
} love_point;

void love_point_new(love_point *self, float _x,float _y);
void love_point_set(love_point *self, float _x,float _y);