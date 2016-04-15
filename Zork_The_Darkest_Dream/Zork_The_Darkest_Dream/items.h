#ifndef __ITEMS_H_
#define __ITEMS_H_

#include "entity.h"

class Item : public Entity {
public:
	Item(){}
	Item(String n, String desc) {
		name = n;
		description = desc;
		type = ITEM;
	}
	~Item(){}
};

#endif