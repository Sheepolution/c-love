// Example program:
// Using SDL2 to create an application window

#include <SDL2/SDL.h>
#include <stdio.h>
#include "love.h"

love_image test;

void update();
void draw();

int main(int argc, char* argv[]) {
    // love_init(300,300,update);
    love_init(300,300,&update,&draw);
    test = love_graphics_newImage();
    return 0;
}

void update() {
}

void draw() {
    love_graphics_draw(test);
}