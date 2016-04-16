#include "entity.h"
#include <stdio.h>

void Entity::Look() {
	printf("\n - %s\n\n %s", this->name.c_str(), this->description.c_str());
	if (this->type == ROOM) {
		bool empty = true;
		for (int k = 0; k < inside.n_size() && empty == true; k++) {
			if (inside[k]->type == ITEM)
				empty = false;
		}
		if (empty == false) {
			printf("\n\n  Items in this room:");
			for (int i = 0; i < inside.n_size(); i++) {
				if (inside[i]->type == ITEM) {
					printf("\n   '%s'", inside[i]->tag.c_str());
				}
			}
		}
	}
}