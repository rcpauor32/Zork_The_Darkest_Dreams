#include <stdio.h>
#include "world.h"
#include "player.h"
#include "exit.h"
#include <stdlib.h>

void Player::Go(String dir) {
	bool success = false;

	for (int i = 0; i < NUM_EXITS; i++) {
		if (current_room == world.exits[i]->nextroom && world.exits[i]->prevdir == dir) {
			success = true;
			if (world.exits[i]->open == false)
				printf("\nThis door is closed, try opening it");
			else {
				current_room = world.exits[i]->prevroom;
				system("CLS");
				world.rooms[GetRoomNum(current_room)]->Look();
			}
		}
		if (current_room == world.exits[i]->prevroom && world.exits[i]->nextdir == dir && success == false) {
			success = true;
			if (world.exits[i]->open == false)
				printf("\nThis door is closed, try opening it");
			else {
				current_room = world.exits[i]->nextroom;
				system("CLS"); 
				world.rooms[GetRoomNum(current_room)]->Look();
			}
		}
	}

	if (success == false)
		printf("\n\nThere's nothing on that direction\n");

}

void Player::PickDrop(String action, String item) {
	bool success = false;
	
	if (action == "pick") {
		if (inventory_limit > 0) {
			for (int i = 0; i < world.rooms[GetRoomNum(current_room)]->inside.n_size(); i++) {
				if (item == world.rooms[GetRoomNum(current_room)]->inside[i]->tag) {
					this->inside.push_back(world.rooms[GetRoomNum(current_room)]->inside[i]);
					world.rooms[GetRoomNum(current_room)]->inside.pop(world.rooms[GetRoomNum(current_room)]->inside[i]);
					success = true;
					inventory_limit--;
					break;
				}
			}
		}
		else
			printf("\nYou cannot pick that, you have already reached your inventory limit.");

		if (success == true) {
			printf("\nYou managed to pick that item.");
		}
	}

	else if (action == "drop") {
		for (int i = 0; i < this->inside.n_size(); i++) {
			if (item == this->inside[i]->tag) {
				world.rooms[GetRoomNum(current_room)]->inside.push_back(this->inside[i]);
				this->inside.pop(this->inside[i]);
				success = true;
				inventory_limit++;
				break;
			}
		}
		if (success == true) {
			printf("\nYou managed to drop that item.");
		}
	}
}

