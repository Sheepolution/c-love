typedef struct {
	love_image img;
	int frame;
	float frameStep;
	float speed;
	int width, height,start,stop;
	char* type;
	love_quad quads[100];
	
} Animation;

#include "animation.h"

void Animation_new(Animation *self,char* url,int w,int h) {
	self->speed = 1;
	self->frameStep = 0;
	self->frame = 0;

	self->img = love_graphics_newImage(url);
	self->width = w;
	self->height = h;
	int i,y,x;
	for (y = 0; y < love_image_getHeight(self->img)/h; ++y) {
		for (x = 0; x < love_image_getWidth(self->img)/w; ++x) {
			self->quads[i] = love_graphics_newQuad(x*w,y*h,w,h);	
			i++;
		}
	}
}

void Animation_update(Animation *self, float dt) {
	if (self->start > self->frame || self->stop+1 < self->frame) {
		self->frameStep = self->start;
	}

	self->frameStep += self->speed * dt;
	if (self->frameStep > self->stop+1) {
		self->frameStep -= (self->stop - self->start)+1;
		// self->frameStep = self->start;
	}
	self->frame = floor(self->frameStep);
}

void Animation_draw(Animation *self,float x, float y) {
	love_graphics_drawq(self->img,self->quads[self->frame],x,y);
}

void Animation_drawEx(Animation *self,float x, float y, double r, float sx, float sy, float ox, float oy) {
	love_graphics_drawqEx(self->img,self->quads[self->frame],x,y,r,sx,sy,ox,oy);
}

void Animation_set(Animation *self,float start, float end, float speed) {
	self->start = start;
	self->stop = end;
	self->speed = speed;
}