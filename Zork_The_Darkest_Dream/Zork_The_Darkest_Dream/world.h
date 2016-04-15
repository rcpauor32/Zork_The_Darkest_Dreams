#ifndef __WORLD_H__
#define	__WORLD_H__

#define NUM_ENTITIES 22

#include "exit.h"
#include "room.h"
#include "items.h"
#include "dynarray.h"


class Entity;
class Room;
class Exit;
class Player;

class World {
public:
	DynArray<Entity*>entities;
	DynArray<Room*>rooms;
	DynArray<Exit*>exits;
	DynArray<Item*>items;
	Player* player;
	
public:
	World();
	~World();
	bool Play();
	
};

extern World world;

enum room_names{
	Secret = 0,
	Surgery,
	UpAngel,
	Studio,
	DwAngel,
	Stone,
	Mirror,
	Waiting,
	Reception,
	Library,
	Darkness
};

enum exit_names{
	SecretRoomDoor = 0,
	SurgeryDoor,
	StudioDoor,
	Stairway,
	StoneDoor,
	MirrorDoor,
	DoubleDoor,
	HospitalDoor,
	WoodenDoor,
	SecretPassage
};

enum item_names {
	TeddyB = 0,
	RustyK,
	BMarble,
	RMarble,
	GMarble,
	SSkull,
	SHeart,
	BGem,
	RGem,
	Lamp,
	Newspaper,
	Notebook
};

#endif