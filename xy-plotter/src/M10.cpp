/*
 * M10.cpp
 *
 *  Created on: 23 Sep 2020
 *      Author: johan
 */

#include "M10.h"

M10::M10() {
	// TODO Auto-generated constructor stub
}

std::string M10::reply(std::vector<std::string> str_,struct Tasks *t){

	char buffer[100];
	sprintf ( buffer," M 10 XY %d %d 0.00 0.00 A%d B%d H0 S%d U%d D%d\r\nOK\r\n", t->height,t->width,t->direktionX,t->directionY,t->speed,t->penUp,t->penDown);
	std::string str = buffer;
	return str;
}

