#ifndef ___ROOM_H___
#define	___ROOM_H___

#include "entity.h"

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

#endif