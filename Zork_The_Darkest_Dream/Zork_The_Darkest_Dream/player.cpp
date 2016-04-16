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
		else {
			printf("\nYou cannot pick that, you have already reached your inventory limit.");
			success = true;
		}
		if (success == true) {
			printf("\nYou managed to pick that item.");
		}
		else {
			printf("\nThere is no such Item in that room.");
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
		else {
			printf("\nThere is no such Item in your inventory.");
		}
	}
}

void Player::LookInv() {
	printf("\n  INVENTORY:");
	if (inside.n_size() == 0) {
		printf("\n You have no items in your inventory.");
	}
	else
		for (int i = 0; i < inside.n_size(); i++) {
			if (inside[i]->type == ITEM) {
				printf("\n - %s.", inside[i]->tag.c_str());
			}
		}
}
