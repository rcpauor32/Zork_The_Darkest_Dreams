#ifndef __ENTITY_H__
#define	__ENTITY_H__

#include "my_string.h"

enum entity_type {
	ROOM = 0,
	EXIT,
	PLAYER
};

class Entity {
public:
	String name;
	String description;
	entity_type type;

public:
	Entity(){};
	Entity(String n, String desc, entity_type t) {
		name = n;
		description = desc;
		type = t;
	}
	virtual ~Entity(){};
	void Look();
};

#endif