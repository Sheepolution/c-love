#include "game.h"

Player myPlayer;
void game_load () {
	Player_load(&myPlayer);
}

void game_update () {
	Player_update(&myPlayer);

}

void game_draw() {
	Player_draw(&myPlayer);

}