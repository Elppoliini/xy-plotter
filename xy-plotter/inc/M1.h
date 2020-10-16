/*
 * M1.h
 *
 *  Created on: 23 Sep 2020
 *      Author: johan
 */

#ifndef M1_H_
#define M1_H_
#include "chip.h"
#include "board.h"
#include <string>
#include <vector>
#include "Tasks.cpp"
#include "ITM_write.h"
#include "DigitalIoPin.h"
#include "PWM_settings.h"

/* Class for setting pen position */
class M1 {
public:
	M1();
	~M1() = default;
	std::string reply(std::vector<std::string> str_,struct Tasks *t); // receive the incomming vector with commannds and set the pen position
private:
	std::vector<std::string> str; // a vector where we can copy the incomming vector to
	bool isNumber(int pos); // check if value is number
};

#endif /* M1_H_ */
