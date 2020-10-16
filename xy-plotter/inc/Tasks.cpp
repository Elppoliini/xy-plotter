/*
 * Tasks.cpp
 *
 *  Created on: 23 Sep 2020
 *      Author: johan
 */

#ifndef TASKS_CPP_
#define TASKS_CPP_
#include <string>

/* Structure where the Gcode settings are saved to*/
struct Tasks{
	int width = 0;
	int height = 0;
	int direktionX = 0;
	int directionY = 0;
	int speed = 50;
	int penUp = 0;
	int penDown = 0;
	int laserPow = 0;
	bool limYP = false;
	bool limYM = false;
	bool limXP = false;
	bool limXM = false;
	double xCord = 0.0; //mm
	double yCord = 0.0; //mm
	std::string command;
	double y1; //step
	double x1; // step
	double y0 = 0; //step
	double x0 = 0; // step
	double stepsize;
};


#endif /* TASKS_CPP_ */
