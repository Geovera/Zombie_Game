/*
 * Zombie.cpp
 *
 *  Created on: May 1, 2018
 *      Author: evan
 */

#include "Zombie.h"

Zombie::Zombie(char* path) {
	// TODO Auto-generated constructor stub
	imagePath = path;
	zombieTexture=NULL;
	destR.h=64;
	destR.w=64;
	destR.x=100;
	destR.y=100;
}

Zombie::~Zombie() {
	// TODO Auto-generated destructor stub
}

