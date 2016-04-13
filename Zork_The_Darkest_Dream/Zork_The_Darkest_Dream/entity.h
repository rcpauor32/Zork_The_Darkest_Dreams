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
	virtual ~Entity(){};
	void Look();
};

#endif