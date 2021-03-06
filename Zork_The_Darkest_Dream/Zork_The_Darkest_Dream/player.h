#ifndef ___PLAYER_H__
#define ___PLAYER_H__

#include "entity.h"


class Player : public Entity {
public:
	String current_room;
	DynArray<Item*>equiped;
	int inventory_limit;
	uint hp;
	
public:
	Player() {
		current_room = "Surgery";
		type = PLAYER;
		inventory_limit = 5;
		hp = 1;
	}
	Player(String n, String desc, String room = "Surgery Room") {
		name = n;
		description = desc;
		current_room = room;
		type = PLAYER;
		inventory_limit = 5;
		can_hold = true;
		hp = 1;
	}

	~Player(){}

	void Go(String dir);
	void PickDrop(String action, String item);
	void LookInv();
	void PutGet(String action, String object, String Dest);
	void EquipUnequip(String action, String item);

};

#endif