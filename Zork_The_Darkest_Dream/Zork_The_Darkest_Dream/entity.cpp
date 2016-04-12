#include "entity.h"
#include <stdio.h>

void Entity::Look() {
	printf("\n\nYou look to the %s\n\n %s", name, description);
}