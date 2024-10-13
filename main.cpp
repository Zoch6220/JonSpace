#include "main.h"
#include "Game.h"

int main() {
	//random number generator
	srand(time(NULL));
	Game game;
	game.run();
	return 0;

}