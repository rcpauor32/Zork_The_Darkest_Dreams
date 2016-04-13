#ifndef ___ROOM_H___
#define	___ROOM_H___

#include "entity.h"

#define NUM_ROOMS 11

class Room : public Entity {
public:
	Room() {}
	Room(String title, String desc) {
		name = title;
		description = desc;
		type = ROOM;
	}

	~Room(){}
};

int GetRoomNum(String room);

#endif