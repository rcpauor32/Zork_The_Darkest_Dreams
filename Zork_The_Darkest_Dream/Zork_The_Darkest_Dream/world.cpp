#include "world.h"
#include "room.h"
#include "exit.h"
#include "player.h"
#include "globals.h"

World::World() {

	//Passing all Rooms
	int i = 0;
	rooms[i++] = new Room("Secret Room", secretdesc);
	rooms[i++] = new Room("Surgery Room", surdesc);
	rooms[i++] = new Room("Upstairs Angel Room", upadesc);
	rooms[i++] = new Room("Studio", studdesc);
	rooms[i++] = new Room("Downstairs Angel Room", dwadesc);
	rooms[i++] = new Room("Stone Room", stondesc);
	rooms[i++] = new Room("Mirror Room", mirrdesc);
	rooms[i++] = new Room("Waiting Room", waitdesc);
	rooms[i++] = new Room("Reception", recepdesc);
	rooms[i++] = new Room("Library", libdesc);
	rooms[i++] = new Room("Darkness", darkdesc);

	//Passing all Exits
	i = 0;
	exits[i++] = new Exit("south", "north", "Surgery Room", "Secret Room", "Wall Crack", sectosurretdesc);
	exits[i++] = new Exit("south", "north", "Upstairs Angel Room", "Surgery Room", "Surgery Door", surtoupadesc, false);
	exits[i++] = new Exit("west", "east", "Studio", "Upstairs Angel Room", "Decorated Wooden Door", upatostuddesc, false);
	exits[i++] = new Exit("down", "up", "Downstairs Angel Room", "Upstairs Angel Room", "Huge Stairway", upatodwadesc);
	exits[i++] = new Exit("west", "east", "Stone Room", "Downstairs Angel Room", "Stone Door", dwatostondesc);
	exits[i++] = new Exit("south", "north", "Stone Room", "Mirror Room", "Glass Door", stontomirrdesc);
	exits[i++] = new Exit("south", "north", "Waiting Room", "Downstairs Angel Room", "White Double Door", dwatowaitdesc);
	exits[i++] = new Exit("south", "north", "Reception", "Waiting Room", "Hospital Door", waittorecepdesc);
	exits[i++] = new Exit("east", "west", "Library", "Downstairs Angel Room", "Wooden Door", dwatolibdesc);
	exits[i++] = new Exit("south", "north", "Darkness", "Library", "Dark Secret Passage", libtodarkdesc);

	//Passing Player
	player = new Player("Hero", playerdesc);

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