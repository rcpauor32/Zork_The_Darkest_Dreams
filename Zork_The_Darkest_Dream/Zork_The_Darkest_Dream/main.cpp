#include "world.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>

World world;

int main() {

	bool EXIT = true;
	char player_name[20];
	char player_desc[200];

	printf("A broken old voice asks from the surrounding shadows:\n   'Please, tell me your name.'\n\n--> ");
	gets_s(player_name, 20);
	world.player->name = player_name;

	printf("Soon, that same voice continues:\n   'And... Who are you?'\n\n--> ");
	gets_s(player_desc, 200);
	world.player->description = player_desc;

	printf("\nNow, your adventure begins...\n\n");
	system("pause");

	system("CLS");

	printf("Welcome to Zork: The Darkest Dreams\n\n");

	system("pause");
	system("CLS");

	printf("\n\nYou have awaken in a dark room, when you eyes start to see, you realize is an odd and old Surgery room.\nWhat are you doing here?\n\n");

	world.rooms[GetRoomNum(world.player->current_room)]->Look();

	while (EXIT) {
		EXIT = world.Play();
	}

	printf("\nThanks for Playing :D\nBye!");

	getchar();

	return 0;
}