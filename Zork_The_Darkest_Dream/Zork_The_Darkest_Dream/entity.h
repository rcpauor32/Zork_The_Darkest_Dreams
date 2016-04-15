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
	entity_type type;
	DynArray <Entity*>inside;

public:
	Entity(){};
	virtual ~Entity(){};
	void Look();
};

#endif