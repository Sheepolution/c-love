#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include "love.c"
#include "animation.c"
#include "player.c"
#include "bullet.c"
#include "game.c"

int main(int argc, char* argv[]) {
	int test = 4;
    love_init(500,300);
    return 0;
}

void love_load() {
    game_load();
}

void love_update(float dt) {
    game_update(dt);
}

void love_draw() {
    game_draw();
}

void love_keypressed(char *key) {
	
}

void love_keyreleased(char *key) {
	
}