#include "entity.h"
#include <stdio.h>

void Entity::Look() {
	printf("\n\n - %s\n\n %s", this->name.c_str(), this->description.c_str());
}