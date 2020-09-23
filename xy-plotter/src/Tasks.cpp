/*
 * Tasks.cpp
 *
 *  Created on: 23 Sep 2020
 *      Author: johan
 */

#ifndef TASKS_CPP_
#define TASKS_CPP_
#include <string>

struct Tasks{
	int width = 0;
	int height = 0;
	int direktionX = 0;
	int directionY = 0;
	int speed = 0;
	int penUp = 0;
	int penDown = 0;
	int laserPow = 0;
	bool limYP = false;
	bool limYM = false;
	bool limXP = false;
	bool limXM = false;
	float xCord = 0.0;
	float yCord = 0.0;
	std::string command;
};


#endif /* TASKS_CPP_ */
