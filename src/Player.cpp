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
	destR.h=150;
	destR.w=150;
	destR.x=200;
	destR.y=300;
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

