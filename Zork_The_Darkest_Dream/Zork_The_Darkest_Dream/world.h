#ifndef __WORLD_H__
#define	__WORLD_H__

#define NUM_ENTITIES 22

#include "exit.h"
#include "room.h"
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
	Player* player;
	
public:
	World();
	~World();
	bool Play();
	
};

extern World world;

#endif