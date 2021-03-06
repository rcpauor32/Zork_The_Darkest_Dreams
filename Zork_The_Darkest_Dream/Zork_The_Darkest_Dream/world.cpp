#include "world.h"
#include "room.h"
#include "exit.h"
#include "items.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>

World::World() {

	//Passing all Rooms
	rooms.push_back(new Room("Secret Room", "This is a dark room only lighted up by the fading light of your torch.\n After a moment you realize there is a man - like hooded figure standing in a corner.\n He doesn't seem to have noticed you yet.\n The only visible door is to the SOUTH.\n"));
	rooms.push_back(new Room("Surgery Room", "This is an old surgery room from hell itself. There's a wallcrack on the NORTH wall and a door to the SOUTH"));
	rooms.push_back(new Room("Upstairs Angel Room", "You can see a huge statue of an angel that grows from the lower floor. There's a decorated portal to the WEST, a door to the NORTH and a big STAIRWAY direction DOWN."));
	rooms.push_back(new Room("Studio", "It's a little studio with a drawer int it. The only portal is to the EAST."));
	rooms.push_back(new Room("Downstairs Angel Room", "The angel statue is placed on the middle of the room. There's a stone gate to the WEST, a white door to the SOUTH and a wooden door to the EAST."));
	rooms.push_back(new Room("Stone Room", "The whole room is made of stone. There's a woman-like statue that is covering her eyes with her hands. There is a way to the SOUTH and another to the EAST."));
	rooms.push_back(new Room("Mirror Room", "The whole room is covered in mirrors and glass. The only way out is to the NORTH."));
	rooms.push_back(new Room("Waiting Room", "This is a big waiting room from and old hospital. There is a door to the NORTH and another to the SOUTH."));
	rooms.push_back(new Room("Reception", "This is and old reception from a hospital, it results strangly familiar. There's a big door with a red sign that reads: 'EXIT' but it is totally jammed.\nThe only viable way is to the NORTH."));
	rooms.push_back(new Room("Library", "This is a huge library plenty of dusty books. There is a wooden door to the WEST and a secret passage to the SOUTH."));
	rooms.push_back(new Room("Darkness", "This 'room' if it is even that, is made of pure darkness, not even the light of your lamp can go through it. The only way (except from the infinite darkness) is a passage to the NORTH."));

	//Passing all Exits
	exits.push_back(new Exit("south", "north", "Surgery Room", "Secret Room", "Wallcrack", "A huge wallcrack on the wall. Seems that I could sneak through it.", "wallcrack"));
	exits.push_back(new Exit("south", "north", "Upstairs Angel Room", "Surgery Room", "Surgery Door", "A big white door with the sign 'Surgery Room' on it.", "door",  false));
	exits.push_back(new Exit("west", "east", "Studio", "Upstairs Angel Room", "Decorated Portal", "A decorated wooden door with old fashioned relief.", "portal" ,  false));
	exits.push_back(new Exit("down", "up", "Downstairs Angel Room", "Upstairs Angel Room", "Huge Stairway", "A huge stairway that goes around the great statue of an decapitated angel.", "stairway"));
	exits.push_back(new Exit("west", "east", "Stone Room", "Downstairs Angel Room", "Stone Gate", "A gate made of polished stone.", "gate"));
	exits.push_back(new Exit("south", "north", "Mirror Room", "Stone Room", "Glass Door", "exit__", "door"));
	exits.push_back(new Exit("south", "north", "Waiting Room", "Downstairs Angel Room", "White Double Door", "A bif double door that seems gotten from a hospital.", "portal"));
	exits.push_back(new Exit("south", "north", "Reception", "Waiting Room", "Hospital Gate", "A strangly familiar hospital gate with the sign 'Reception' on it.", "gate"));
	exits.push_back(new Exit("east", "west", "Library", "Downstairs Angel Room", "Wooden Door","An old wooden door I can hear something behind it.", "door"));
	exits.push_back(new Exit("south", "north", "Darkness", "Library", "Dark Secret Passage", "A dark entrance that connects the library with pure darkness.", "passage"));

	//Passing Player
	player = new Player("Hero", "plyer_desc");

	//Passing Items
	items.push_back(new Item("Teddy Bear", "An old and unsew Teddy Bear, it has an eye missing.", "bear"));
	items.push_back(new Item("Rusty Key", "An old rusty key that seems to have been trough a lot of things.", "key"));
	items.push_back(new Item("Blue Marble", "A blue marble.", "marble"));
	items.push_back(new Item("Red Marble", "A red marble.", "marble"));
	items.push_back(new Item("Green Marble", "A green marble.", "marble"));
	items.push_back(new Item("Stone Skull", "A creepy skull made of stone, it is way to big to be from a human.", "skull", 1, true));
	items.push_back(new Item("Stone Heart", "A heart made of stone, you feel like somthing is beating inside.", "heart", 1, true, false, true));
	items.push_back(new Item("Blue Gem", "A blue hexagonal gem.", "gem"));
	items.push_back(new Item("Red Gem", "A red hexagonal gem.", "gem"));
	items.push_back(new Item("Lamp", "An old but still-working lamp.", "lamp"));
	items.push_back(new Item("Newspaper Sheet", "a sheet from an out of date newspaper, it has some news from a car accident.", "newspaper"));
	items.push_back(new Item("Child Notebook", "A notebook from a child. It is plenty of childish draws.", "notebook"));
	
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
	bool recognized = true;
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
		else if (input == "s\n" || input == "south\n") {
			player->Go("south");
		}
		else if (input == "w\n" || input == "west\n") {
			player->Go("west");
		}
		else if (input == "e\n" || input == "east\n") {
			player->Go("east");
		}
		else if (input == "u\n" || input == "up\n") {
			player->Go("up");
		}
		else if (input == "d\n" || input == "down\n") {
			player->Go("down");
		}
		else if (input == "q\n" || input == "quit\n") {
			return false;
		}
		else if (input == "clear\n") {
			system("CLS");
			rooms[GetRoomNum(player->current_room)]->Look();
		}
		else if (input == "inventory\n" || input == "inv\n" || input == "i\n") {
			player->LookInv();
		}
		else if (input == "stats\n") {
			printf("\nSTATS:\n Hit Points: %d\n --- end of stats ---\n (did you expect anything else?)", player->hp);
		}
		else
			recognized = false;
		break;

	case 2:
		if (input.GetChoosenArg(1) == "go") {
			if (input.GetChoosenArg(2) == "n" || input.GetChoosenArg(2) == "north") {
				player->Go("north");
			}
			else if (input.GetChoosenArg(2) == "s" || input.GetChoosenArg(2) == "south") {
				player->Go("south");
			}
			else if (input.GetChoosenArg(2) == "w" || input.GetChoosenArg(2) == "west") {
				player->Go("west");
			}
			else if (input.GetChoosenArg(2) == "e" || input.GetChoosenArg(2) == "east") {
				player->Go("east");
			}
			else if (input.GetChoosenArg(2) == "u" || input.GetChoosenArg(2) == "up") {
				player->Go("up");
			}
			else if (input.GetChoosenArg(2) == "d" || input.GetChoosenArg(2) == "down") {
				player->Go("down");
			}
			else
				printf("\nI do not recognize that direction");
		}
		else if (input.GetChoosenArg(1) == "look") {
			bool looked = false;
			if (input.GetChoosenArg(2) == "north" || input.GetChoosenArg(2) == "south" || input.GetChoosenArg(2) == "west" || input.GetChoosenArg(2) == "east" || input.GetChoosenArg(2) == "up" || input.GetChoosenArg(2) == "down"){
				for (int i = 0; i < NUM_EXITS; i++) {
					if (player->current_room == world.exits[i]->nextroom && world.exits[i]->prevdir == input.GetChoosenArg(2)) {
						exits[i]->Look();
						looked = true;
					} 
					else if (player->current_room == world.exits[i]->prevroom && world.exits[i]->nextdir == input.GetChoosenArg(2)) {
						exits[i]->Look();
						looked = true;
					}
				}
				if (looked == false) {
					printf("There's no exit to that direction.");
					looked = true;
				}
			}
			else if (input.GetChoosenArg(2) == "room") {
				rooms[GetRoomNum(player->current_room)]->Look();
				looked = true;
			}
			else if (input.GetChoosenArg(2) == "player") {
				player->Look();
				looked = true;
			}
			else 
				for (int i = 0; i < rooms[GetRoomNum(player->current_room)]->inside.n_size(); i++) {
				if (input.GetChoosenArg(2) == rooms[GetRoomNum(player->current_room)]->inside[i]->tag) {
					rooms[GetRoomNum(player->current_room)]->inside[i]->Look();
					looked = true;
				}
			}
			for (int i = 0; i < player->inside.n_size(); i++) {
				if (input.GetChoosenArg(2) == player->inside[i]->tag) {
					player->inside[i]->Look();
					looked = true;
				}
			}
			if (looked == false)
				printf("\nThere's no such thing in this room.");
		}
		else if (input.GetChoosenArg(1) == "close" || input.GetChoosenArg(1) == "open") {
			bool success = false;
			if (input.GetChoosenArg(2) == "north" || input.GetChoosenArg(2) == "south" || input.GetChoosenArg(2) == "west" || input.GetChoosenArg(2) == "east" || input.GetChoosenArg(2) == "up" || input.GetChoosenArg(2) == "down"){
				for (int i = 0; i < NUM_EXITS; i++) {
					if (player->current_room == world.exits[i]->nextroom && world.exits[i]->prevdir == input.GetChoosenArg(2)) {
						if (exits[i]->open == true && input.GetChoosenArg(1) == "open") {
							printf("\nThat door is already open.");
							success = true;
						}
						else if (exits[i]->open == false && input.GetChoosenArg(1) == "close") {
							printf("\nThat door is already closed.");
							success = true;
						}
						else {
							exits[i]->OpenClose(input.GetChoosenArg(1));
							success = true;
						}
					}
					else if (player->current_room == world.exits[i]->prevroom && world.exits[i]->nextdir == input.GetChoosenArg(2)) {
						if (exits[i]->open == true && input.GetChoosenArg(1) == "open") {
							printf("\nThat door is already open.");
							success = true;
						}
						else if (exits[i]->open == false && input.GetChoosenArg(1) == "close") {
							printf("\nThat door is already closed.");
							success = true;
						}
						else {
							exits[i]->OpenClose(input.GetChoosenArg(1));
							success = true;
						}
					}
				}
				if (success == false) {
					printf("There's no such door to that direction.");
				}
			}
		}
		else if (input.GetChoosenArg(1) == "pick" || input.GetChoosenArg(1) == "drop") {
			player->PickDrop(input.GetChoosenArg(1), input.GetChoosenArg(2));
		}
		else if (input.GetChoosenArg(1) == "equip" || input.GetChoosenArg(1) == "unequip") {
			player->EquipUnequip(input.GetChoosenArg(1), input.GetChoosenArg(2));
		}
		else
			recognized = false;
		break;

		case 3:
			break;
		case 4: 
			if (input.GetChoosenArg(1) == "put" && input.GetChoosenArg(3) == "in" || input.GetChoosenArg(1) == "get" && input.GetChoosenArg(3) == "from") {
				player->PutGet(input.GetChoosenArg(1), input.GetChoosenArg(2), input.GetChoosenArg(4));
			}
			else
				recognized = false;
	}
	
	if (recognized == false) {
		printf("\nThere's no such command.");
	}

	return true;
}