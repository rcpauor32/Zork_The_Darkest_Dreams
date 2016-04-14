#include "world.h"
#include "player.h"
#include <stdio.h>

World world;

int main() {

	bool EXIT = true;

	String test = "hello world\n";

	world.player->Go("north");
	world.player->Go("south");

	printf("\n%d", test.GetnArgs());
	printf("\n%s", test.GetChoosenArg(2));

	while (EXIT) {
		EXIT = world.Play();
	}

	printf("\nThanks for Playing :D\nBye!");

	getchar();

	return 0;
}