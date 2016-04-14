#include "world.h"
#include "player.h"
#include <stdio.h>

World world;

int main() {

	bool EXIT = true;

	world.player->Go("north");
	world.player->Go("south");

	while (EXIT) {
		EXIT = world.Play();
	}

	printf("\nThanks for Playing :D\nBye!");

	getchar();

	return 0;
}