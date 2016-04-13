#include "room.h"

int GetRoomNum(String room) {
	int room_num;

	if (room == "Secret Room")
		room_num = 0;
	if (room == "Surgery Room")
		room_num = 1;
	if (room == "Upstairs Angel Room")
		room_num = 2;
	if (room == "Studio")
		room_num = 3;
	if (room == "Downstairs Angel Room")
		room_num = 4;
	if (room == "Stone Room")
		room_num = 5;
	if (room == "Mirror Room")
		room_num = 6;
	if (room == "Waiting Room")
		room_num = 7;
	if (room == "Reception")
		room_num = 8;
	if (room == "Library")
		room_num = 9;
	if (room == "Darkness")
		room_num = 10;

	return room_num;
}
