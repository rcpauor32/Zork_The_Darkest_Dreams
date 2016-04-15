#include <stdio.h>
#include "exit.h"

void Exit::OpenClose(String action) {
	if (action == "open") {
		this->open = true;
		printf("\nYou have successfully opened the door!");
	}
	else if(action == "close") {
		this->open = false;
		printf("\nYou achieved to close that door!");
	}
}