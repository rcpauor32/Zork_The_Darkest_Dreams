#ifndef  ___EXIT_H___
#define	 ___EXIT_H___

#include "entity.h"

#define NUM_EXITS 10

class Exit : public Entity {
public:
	String nextdir;
	String prevdir;
	String nextroom;
	String prevroom;

	bool open;

public:
	Exit(){}
	Exit(String nextd, String prevd, String nextr, String prevr, String n, String desc, String t, bool state = true) {
		nextdir = nextd;
		prevdir = prevd;
		nextroom = nextr;
		prevroom = prevr;
		name = n;
		description = desc;
		open = state;
		tag = t;
		type = EXIT;
	}

	~Exit(){};

	void OpenClose(String action);
};

#endif