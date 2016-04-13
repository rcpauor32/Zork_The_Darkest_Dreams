#include "world.h"
#include "player.h"
#include <stdio.h>

World world;

int main() {

	world.player->Go("north");
	world.player->Go("south");
	world.player->Go("west");
	world.player->Go("east");


	getchar();

	return 0;
}