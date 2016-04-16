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
				printf("\n - %s", inside[i]->tag.c_str());
				if (inside[i]->is_inside == true) {
					printf(" (inside %s)", inside[i]->container_name.c_str());
				}
				else if (inside[i]->is_equiped == true) {
					printf(" *equiped*");
				}
			}
		}
}

void Player::PutGet(String action, String object, String dest) {
	bool obj_exists = false;
	bool dest_exists = false;
	bool posible = true;
	int obj_pos;
	int dest_pos;

	if (object == dest) {
		posible = false;
	}
	else 
	for (int i = 0; i < this->inside.n_size(); i++) {
		if (object == this->inside[i]->tag && this->inside[i]->type == ITEM) {
			obj_exists = true;
			obj_pos = i;
		}
		if (dest == this->inside[i]->tag && this->inside[i]->type == ITEM) {
			dest_exists = true;
			dest_pos = i;
		}
	}
	if (obj_exists && dest_exists) {
		if (action == "put") {
			if (inside[dest_pos]->is_inside == true || inside[obj_pos]->is_inside == true ){
				posible = false;
			}
			else if (inside[dest_pos]->hold_capacity <= 0) {
				printf("You cannot do that. It has reached its maximum capacity");
				posible = true;
			}
			else
			if (this->inside[dest_pos]->can_hold == true) {
				this->inside[dest_pos]->inside.push_back(this->inside[obj_pos]);
				inside[obj_pos]->is_inside = true;
				inside[obj_pos]->container_name = inside[dest_pos]->tag;
				inside[dest_pos]->hold_capacity--;
				printf("You have successfully put %s in %s", object.c_str(), dest.c_str());
			}
			else posible = false;
		}

		if (action == "get") {
			int obj_pos_indest;
			bool obj_in_dest = false;
			for (int i = 0; i < inside[dest_pos]->inside.n_size(); i++) {
				if (inside[dest_pos]->inside[i]->tag == object && inside[dest_pos]->inside[i]->type == ITEM) {
					obj_pos_indest = i;
					obj_in_dest = true;
				}
			}
			if (obj_in_dest == true) {
				this->inside[dest_pos]->inside.pop(inside[dest_pos]->inside[obj_pos_indest]);
				inside[obj_pos]->is_inside = false;
				inside[dest_pos]->hold_capacity++;
				printf("You have successfully got %s from %s", object.c_str(), dest.c_str());
			}
			else posible = false;
		}
	}
	else posible = false;

	if (posible == false) {
		printf("\nYou cannot do that!");
	}
}

void Player::EquipUnequip(String action, String item) {
	for (int i = 0; i < inside.n_size(); i++) {
		if (inside[i]->tag == item) {
			if (action == "equip") {
				if (inside[i]->type == ITEM && inside[i]->is_equiped == false) {
					equiped.push_back((Item*)inside[i]);
					inside[i]->is_equiped = true;
					printf("\nYou are now wearing a %s. It looks nice on you! :D\n(not really...)", inside[i]->tag.c_str());
				}
				else
					printf("You are already wearing that!");
			}
			else if (action == "unequip") {
				if (inside[i]->type == ITEM && inside[i]->is_equiped == true) {
					equiped.pop((Item*)inside[i]);
					inside[i]->is_equiped = false;
					printf("\nYou have unequipped %s. Now you feel like being nude without it...", inside[i]->tag.c_str());
				}
				else
					printf("\nYou are not even wearing that!");
			}
		}
		else
			printf("\nThere is no such item.");
	}
}
