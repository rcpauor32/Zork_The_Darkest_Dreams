#ifndef __ITEMS_H_
#define __ITEMS_H_

#include "entity.h"

class Item : public Entity {	
public:
	Item(){}
	Item(String n, String desc, String t, uint hcp = 0, bool chld = false, bool equi = false, bool ghp = false) {
		name = n;
		description = desc;
		tag = t;
		type = ITEM;
		can_hold = chld;
		hold_capacity = hcp;
		is_equiped = equi;
		give_hp = ghp;
	}
	~Item(){}
};

#endif