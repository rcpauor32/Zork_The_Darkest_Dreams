#ifndef ___PLAYER_H__
#define ___PLAYER_H__

#include "entity.h"


class Player : public Entity {
public:
	String current_room;
	
public:
	Player() {
		current_room = "Surgery";
		type = PLAYER;
	}
	Player(String n, String desc, String room = "Surgery") {
		name = n;
		description = desc;
		current_room = room;
		type = PLAYER;
	}

	~Player(){}

	void Go(String dir);

};

#endif