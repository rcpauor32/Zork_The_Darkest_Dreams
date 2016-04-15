#include "world.h"
#include "room.h"
#include "exit.h"
#include "player.h"
#include <stdio.h>

World::World() {

	//Passing all Rooms
	rooms.push_back(new Room("Secret Room", "room__secretdesc"));
	rooms.push_back(new Room("Surgery Room", "room__surdesc"));
	rooms.push_back(new Room("Upstairs Angel Room", "room__upadesc"));
	rooms.push_back(new Room("Studio", "room__studdesc"));
	rooms.push_back(new Room("Downstairs Angel Room", "room__dwadesc"));
	rooms.push_back(new Room("Stone Room", "room__stonedesc"));
	rooms.push_back(new Room("Mirror Room", "room__mirrdesc"));
	rooms.push_back(new Room("Waiting Room", "room__waitdesc"));
	rooms.push_back(new Room("Reception", "room__receptdesc"));
	rooms.push_back(new Room("Library", "room__libdesc"));
	rooms.push_back(new Room("Darkness", "room__darkdesc"));

	//Passing all Exits
	exits.push_back(new Exit("south", "north", "Surgery Room", "Secret Room", "Wall Crack", "exit__secretdesc"));
	exits.push_back(new Exit("south", "north", "Upstairs Angel Room", "Surgery Room", "Surgery Door", "exit__upa", false));
	exits.push_back(new Exit("west", "east", "Studio", "Upstairs Angel Room", "Decorated Wooden Door", "exit__1", false));
	exits.push_back(new Exit("down", "up", "Downstairs Angel Room", "Upstairs Angel Room", "Huge Stairway", "exit__lol"));
	exits.push_back(new Exit("west", "east", "Stone Room", "Downstairs Angel Room", "Stone Door", "exit_jj"));
	exits.push_back(new Exit("south", "north", "Stone Room", "Mirror Room", "Glass Door", "exit__"));
	exits.push_back(new Exit("south", "north", "Waiting Room", "Downstairs Angel Room", "White Double Door", "exit_desc4"));
	exits.push_back(new Exit("south", "north", "Reception", "Waiting Room", "Hospital Door", "exit__mmm"));
	exits.push_back(new Exit("east", "west", "Library", "Downstairs Angel Room", "Wooden Door","exit__345235"));
	exits.push_back(new Exit("south", "north", "Darkness", "Library", "Dark Secret Passage", "exit_dar"));

	//Passing Player
	player = new Player("Hero", "plyer_desc");

	items.push_back(new Item("Teddy Bear", "Teddy desc"));
	items.push_back(new Item("Rusty Key", "Rusty Key desc"));
	items.push_back(new Item("Blue Marble", "BM desc"));
	items.push_back(new Item("Red Marble", "RM desc"));
	items.push_back(new Item("Green Marble", "GM desc"));
	items.push_back(new Item("Stone Skull", "SS desc"));
	items.push_back(new Item("Stone Heart", "SH desc"));
	items.push_back(new Item("Blue Gem", "BG desc"));
	items.push_back(new Item("Red Gem", "RG desc"));
	items.push_back(new Item("Lamp", "Lamp desc"));
	items.push_back(new Item("Newspaper Sheet", "NS desc"));
	items.push_back(new Item("Child Notebook", "CN desc"));
	
	//Passing all exits to each room
	rooms[Secret]->inside.push_back(exits[SecretRoomDoor]);
	rooms[Surgery]->inside.push_back(exits[SecretRoomDoor]);
	rooms[Surgery]->inside.push_back(exits[SurgeryDoor]);
	rooms[UpAngel]->inside.push_back(exits[SurgeryDoor]);
	rooms[UpAngel]->inside.push_back(exits[StudioDoor]);
	rooms[UpAngel]->inside.push_back(exits[Stairway]);
	rooms[DwAngel]->inside.push_back(exits[Stairway]);
	rooms[DwAngel]->inside.push_back(exits[StoneDoor]);
	rooms[DwAngel]->inside.push_back(exits[DoubleDoor]);
	rooms[DwAngel]->inside.push_back(exits[WoodenDoor]);
	rooms[Stone]->inside.push_back(exits[StoneDoor]);
	rooms[Stone]->inside.push_back(exits[MirrorDoor]);
	rooms[Mirror]->inside.push_back(exits[MirrorDoor]);
	rooms[Waiting]->inside.push_back(exits[DoubleDoor]);
	rooms[Waiting]->inside.push_back(exits[HospitalDoor]);
	rooms[Reception]->inside.push_back(exits[HospitalDoor]);
	rooms[Library]->inside.push_back(exits[WoodenDoor]);
	rooms[Library]->inside.push_back(exits[SecretPassage]);
	rooms[Darkness]->inside.push_back(exits[SecretPassage]);

	//Passing items to each room
	rooms[Secret]->inside.push_back(items[TeddyB]);
	rooms[Surgery]->inside.push_back(items[RustyK]);
	rooms[Studio]->inside.push_back(items[SSkull]);
	rooms[DwAngel]->inside.push_back(items[SHeart]);
	rooms[Stone]->inside.push_back(items[RMarble]);
	rooms[Mirror]->inside.push_back(items[BGem]);
	rooms[Mirror]->inside.push_back(items[Lamp]);
	rooms[Library]->inside.push_back(items[Newspaper]);
	rooms[Library]->inside.push_back(items[Notebook]);
	rooms[Darkness]->inside.push_back(items[BMarble]);
	rooms[Darkness]->inside.push_back(items[RGem]);
	rooms[Waiting]->inside.push_back(items[GMarble]);


	//Passing all to entities[]
	entities.push_back(rooms[0]);
	entities.push_back(rooms[1]);
	entities.push_back(rooms[2]);
	entities.push_back(rooms[3]);
	entities.push_back(rooms[4]);
	entities.push_back(rooms[5]);
	entities.push_back(rooms[6]);
	entities.push_back(rooms[7]);
	entities.push_back(rooms[8]);
	entities.push_back(rooms[9]);
	entities.push_back(rooms[10]);
	entities.push_back(exits[0]);
	entities.push_back(exits[1]);
	entities.push_back(exits[2]);
	entities.push_back(exits[3]);
	entities.push_back(exits[4]);
	entities.push_back(exits[5]);
	entities.push_back(exits[6]);
	entities.push_back(exits[7]);
	entities.push_back(exits[8]);
	entities.push_back(exits[9]);
 	entities.push_back(items[0]);
	entities.push_back(items[1]);
	entities.push_back(items[2]);
	entities.push_back(items[3]);
	entities.push_back(items[4]);
	entities.push_back(items[5]);
	entities.push_back(items[6]);
	entities.push_back(items[7]);
	entities.push_back(items[8]);
	entities.push_back(items[9]);
	entities.push_back(items[10]);
	entities.push_back(items[11]);
	entities.push_back(player);
	

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
		if (input.GetChoosenArg(1) == "go") {
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
				if (input.GetChoosenArg(2) == entities[i]->name.c_str()) {
					entities[i]->Look();
				}
			}
		}
		if (input.GetChoosenArg(1) == "close") {
		}
		break;
	}
	
	return true;
}