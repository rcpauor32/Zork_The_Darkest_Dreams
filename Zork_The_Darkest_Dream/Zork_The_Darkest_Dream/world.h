#ifndef __WORLD_H__
#define	__WORLD_H__

#define NUM_ENTITIES 22

#include "exit.h"
#include "room.h"

class Entity;
class Room;
class Exit;
class Player;

class World {
public:
	Entity* entities[NUM_ENTITIES];
	Room* rooms[NUM_ROOMS];
	Exit* exits[NUM_EXITS];
	Player* player;
	
public:
	World();
	~World();
	
};

extern World world;

#endif