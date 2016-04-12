#include "world.h"
#include "room.h"
#include "exit.h"
#include "player.h"
#include "globals.h"

World::World() {
	// Rooms
	Room* secret		= new Room("Secret Room", secretdesc);
	Room* surgery		= new Room("Surgery Room", surdesc);
	Room* up_angel		= new Room("Upstairs Angel Room", upadesc);
	Room* studio		= new Room("Studio", studdesc);
	Room* down_angel	= new Room("Downstairs Angel Room", dwadesc);
	Room* stone			= new Room("Stone Room", stondesc);
	Room* mirror		= new Room("Mirror Room", mirrdesc);
	Room* waiting		= new Room("Waiting Room", waitdesc);
	Room* reception		= new Room("Reception", recepdesc);
	Room* library		= new Room("Library", libdesc);
	Room* darkness		= new Room("Darkness", darkdesc);

	// Exits
	Exit* sec_sur		= new Exit("south", "north", "Surgery Room", "Secret Room", "Wall Crack", sectosurretdesc);
	Exit* sur_upa		= new Exit("south", "north", "Upstairs Angel Room", "Surgery Room", "Surgery Door", surtoupadesc, false);
	Exit* upa_stu		= new Exit("west", "east", "Studio", "Upstairs Angel Room", "Decorated Wooden Door", upatostuddesc,  false);
	Exit* upa_dwa		= new Exit("down", "up", "Downstairs Angel Room", "Upstairs Angel Room", "Huge Stairway", upatodwadesc);
	Exit* dwa_sto		= new Exit("west", "east", "Stone Room", "Downstairs Angel Room", "Stone Door", dwatostondesc);
	Exit* sto_mir		= new Exit("south", "north", "Stone Room", "Mirror Room", "Glass Door", stontomirrdesc);
	Exit* dwa_wai		= new Exit("south", "north", "Waiting Room", "Downstairs Angel Room", "White Double Door", dwatowaitdesc);
	Exit* wai_rec		= new Exit("south", "north", "Reception", "Waiting Room", "Hospital Door", waittorecepdesc);
	Exit* dwa_lib		= new Exit("east", "west", "Library", "Downstairs Angel Room", "Wooden Door", dwatolibdesc);
	Exit* lib_dar		= new Exit("south", "north", "Darkness", "Library", "Dark Secret Passage", libtodarkdesc);

	// Player
	Player* player		= new Player("Hero", playerdesc);

	//Passing all to entities[]
	int i = 0;
	entities[i++] = secret;
	entities[i++] = surgery;
	entities[i++] = up_angel;
	entities[i++] = studio;
	entities[i++] = down_angel;
	entities[i++] = stone;
	entities[i++] = mirror;
	entities[i++] = waiting;
	entities[i++] = reception;
	entities[i++] = library;
	entities[i++] = darkness;
	entities[i++] = sec_sur;
	entities[i++] = sur_upa;
	entities[i++] = upa_stu;
	entities[i++] = upa_dwa;
	entities[i++] = dwa_sto;
	entities[i++] = sto_mir;
	entities[i++] = dwa_wai;
	entities[i++] = wai_rec;
	entities[i++] = dwa_lib;
	entities[i++] = lib_dar;
	entities[i++] = player;

}

World::~World() {
	for (int i = 0; i < NUM_ENTITIES; i++) {
		delete entities[i];
	}
}