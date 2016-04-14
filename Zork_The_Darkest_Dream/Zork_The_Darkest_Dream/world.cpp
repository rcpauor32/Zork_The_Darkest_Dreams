#include "world.h"
#include "room.h"
#include "exit.h"
#include "player.h"
#include <stdio.h>

World::World() {

	//Passing all Rooms
	int i = 0;
	rooms[i++] = new Room("Secret Room", "room__secretdesc");
	rooms[i++] = new Room("Surgery Room", "room__surdesc");
	rooms[i++] = new Room("Upstairs Angel Room", "room__upadesc");
	rooms[i++] = new Room("Studio", "room__studdesc");
	rooms[i++] = new Room("Downstairs Angel Room", "room__dwadesc");
	rooms[i++] = new Room("Stone Room", "room__stonedesc");
	rooms[i++] = new Room("Mirror Room", "room__mirrdesc");
	rooms[i++] = new Room("Waiting Room", "room__waitdesc");
	rooms[i++] = new Room("Reception", "room__receptdesc");
	rooms[i++] = new Room("Library", "room__libdesc");
	rooms[i++] = new Room("Darkness", "room__darkdesc");

	//Passing all Exits
	i = 0;
	exits[i++] = new Exit("south", "north", "Surgery Room", "Secret Room", "Wall Crack", "exit__secretdesc");
	exits[i++] = new Exit("south", "north", "Upstairs Angel Room", "Surgery Room", "Surgery Door", "exit__upa", false);
	exits[i++] = new Exit("west", "east", "Studio", "Upstairs Angel Room", "Decorated Wooden Door", "exit__1", false);
	exits[i++] = new Exit("down", "up", "Downstairs Angel Room", "Upstairs Angel Room", "Huge Stairway", "exit__lol");
	exits[i++] = new Exit("west", "east", "Stone Room", "Downstairs Angel Room", "Stone Door", "exit_jj");
	exits[i++] = new Exit("south", "north", "Stone Room", "Mirror Room", "Glass Door", "exit__");
	exits[i++] = new Exit("south", "north", "Waiting Room", "Downstairs Angel Room", "White Double Door", "exit_desc4");
	exits[i++] = new Exit("south", "north", "Reception", "Waiting Room", "Hospital Door", "exit__mmm");
	exits[i++] = new Exit("east", "west", "Library", "Downstairs Angel Room", "Wooden Door","exit__345235");
	exits[i++] = new Exit("south", "north", "Darkness", "Library", "Dark Secret Passage", "exit_dar");

	//Passing Player
	player = new Player("Hero", "plyer_desc");

	//Passing all to entities[]
	i = 0;
	entities[i++] = rooms[0];
	entities[i++] = rooms[1];
	entities[i++] = rooms[2];
	entities[i++] = rooms[3];
	entities[i++] = rooms[4];
	entities[i++] = rooms[5];
	entities[i++] = rooms[6];
	entities[i++] = rooms[7];
	entities[i++] = rooms[8];
	entities[i++] = rooms[9];
	entities[i++] = rooms[10];
	entities[i++] = exits[0];
	entities[i++] = exits[1];
	entities[i++] = exits[2];
	entities[i++] = exits[3];
	entities[i++] = exits[4];
	entities[i++] = exits[5];
	entities[i++] = exits[6];
	entities[i++] = exits[7];
	entities[i++] = exits[8];
	entities[i++] = exits[9];
	entities[i++] = player;
	

}

World::~World() {
	for (int i = 0; i < NUM_ENTITIES; i++) {
		delete entities[i];
	}
}

bool World::Play() {
	String input;
	char play_input[50];
	printf("\n\n--> ");
	fgets(play_input, 50, stdin);
	
	input = play_input;

	switch (input.GetnArgs()) {
	case 0:
		printf("\n\nThere are too few arguments\n");
		break;
	case 1:
		if (input == "n\n" || input == "north\n") {
			player->Go("north");
		}
		if (input == "s\n" || input == "south\n") {
			player->Go("south");
		}
		if (input == "w\n" || input == "west\n") {
			player->Go("west");
		}
		if (input == "e\n" || input == "east\n") {
			player->Go("east");
		}
		if (input == "u\n" || input == "up\n") {
			player->Go("up");
		}
		if (input == "d\n" || input == "down\n") {
			player->Go("down");
		}
		if (input == "q\n" || input == "quit\n") {
			return false;
		}
		break;

	case 2:
		char* a = input.GetChoosenArg(1);
		if (a == "go") { // a is = "go" but doesnt
			printf("hello");
			if (input.GetChoosenArg(2) == "n\n" || input.GetChoosenArg(2) == "north\n") {
				player->Go("north");
			}
			if (input.GetChoosenArg(2) == "s\n" || input.GetChoosenArg(2) == "south\n") {
				player->Go("south");
			}
			if (input.GetChoosenArg(2) == "w\n" || input.GetChoosenArg(2) == "west\n") {
				player->Go("west");
			}
			if (input.GetChoosenArg(2) == "e\n" || input.GetChoosenArg(2) == "east\n") {
				player->Go("east");
			}
			if (input.GetChoosenArg(2) == "u\n" || input.GetChoosenArg(2) == "up\n") {
				player->Go("up");
			}
			if (input.GetChoosenArg(2) == "d\n" || input.GetChoosenArg(2) == "down\n") {
				player->Go("down");
			}
		}
		if (input.GetChoosenArg(1) == "look") {
			for (int i = 0; i < NUM_ENTITIES; i++) {
			}
		}
		break;
	}
	
	return true;
}