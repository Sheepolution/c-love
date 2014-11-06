void Animation_new(Animation *self,char* url,int w,int h);

void Animation_update(Animation *self, float dt);

void Animation_draw(Animation *self,float x, float y);

void Animation_drawEx(Animation *self,float x, float y, double r, float sx, float sy, float ox, float oy);