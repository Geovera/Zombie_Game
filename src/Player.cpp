/*
 * Player.cpp
 *
 *  Created on: Apr 24, 2018
 *      Author: eliro
 */

#include "Player.h"

Player::Player(char* path) {
	// TODO Auto-generated constructor stub
	imagePath = path;
	playerTexture=NULL;
	destR.h=64;
	destR.w=64;
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

