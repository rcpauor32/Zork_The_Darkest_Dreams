#include "world.h"
#include "player.h"
#include <stdio.h>

World world;

int main() {

	String a = "hello world";

	world.player->Go("north");
	world.player->Go("south");
	world.player->Go("west");
	world.player->Go("east");

	printf("%s", a.GetChoosenArg(2));


	getchar();

	return 0;
}