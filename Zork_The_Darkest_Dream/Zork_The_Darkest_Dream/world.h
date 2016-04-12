#ifndef __WORLD_H__
#define	__WORLD_H__

#define NUM_ENTITIES 22

class Entity;
class Room;
class Exit;
class Player;

class World {
public:
	Entity* entities[NUM_ENTITIES];
	
public:
	World();
	~World();
	
};

#endif