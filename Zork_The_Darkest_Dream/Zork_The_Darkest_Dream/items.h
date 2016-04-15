#ifndef __ITEMS_H_
#define __ITEMS_H_

#include "entity.h"

class Item : public Entity {	
public:
	Item(){}
	Item(String n, String desc, String t) {
		name = n;
		description = desc;
		tag = t;
		type = ITEM;
	}
	~Item(){}
};

#endif