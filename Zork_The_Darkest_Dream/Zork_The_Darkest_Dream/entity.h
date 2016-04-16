#ifndef __ENTITY_H__
#define	__ENTITY_H__

#include "my_string.h"
#include "dynarray.h"


enum entity_type {
	ROOM = 0,
	EXIT,
	PLAYER,
	ITEM
};

class Entity {
public:
	String name;
	String description;
	String tag;
	entity_type type;
	DynArray <Entity*>inside;
	bool can_hold;
	bool is_inside;
	bool is_equiped;
	bool give_hp;
	String container_name;
	uint hold_capacity;

public:
	Entity(){};
	virtual ~Entity(){};
	void Look();
};

#endif