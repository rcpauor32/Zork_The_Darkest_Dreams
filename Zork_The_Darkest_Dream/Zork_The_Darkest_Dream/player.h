#ifndef ___PLAYER_H__
#define ___PLAYER_H__

#include "entity.h"


class Player : public Entity {
public:
	String current_room;
	int inventory_limit;
	
public:
	Player() {
		current_room = "Surgery";
		type = PLAYER;
		inventory_limit = 5;
	}
	Player(String n, String desc, String room = "Surgery Room") {
		name = n;
		description = desc;
		current_room = room;
		type = PLAYER;
		inventory_limit = 5;
	}

	~Player(){}

	void Go(String dir);
	void PickDrop(String action, String item);

};

#endif