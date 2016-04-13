#include <stdio.h>
#include "world.h"
#include "player.h"
#include "exit.h"

void Player::Go(String dir) {
	bool success = false;

	for (int i = 0; i < NUM_EXITS; i++) {
		if (current_room == world.exits[i]->nextroom && world.exits[i]->prevdir == dir) {
			success = true;
			if (world.exits[i]->open == false)
				printf("\nThis door is closed, try opening it");
			else {
				current_room = world.exits[i]->prevroom;
				world.rooms[GetRoomNum(current_room)]->Look();
			}
		}
		if (current_room == world.exits[i]->prevroom && world.exits[i]->nextdir == dir && success == false) {
			success = true;
			if (world.exits[i]->open == false)
				printf("\nThis door is closed, try opening it");
			else {
				current_room = world.exits[i]->nextroom;
				world.rooms[GetRoomNum(current_room)]->Look();
			}
		}
	}

	if (success == false)
		printf("\n\nThere's nothing on that direction\n");

}

