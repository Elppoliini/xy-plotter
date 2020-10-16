/*
 * M4.h
 *
 *  Created on: 23 Sep 2020
 *      Author: johan
 */

#ifndef M4_H_
#define M4_H_
#include <string>
#include <vector>
#include "Tasks.cpp"
#include "ITM_write.h"
#include "PWM_settings.h"

/* Class for setting laser power */
class M4 {
public:
	M4();
	~M4() = default;
	std::string reply(std::vector<std::string> str_,struct Tasks *t); // receive the incomming vector with commannds and set the laser power
private:
	std::vector<std::string> str; // a vector where we can copy the incomming vector to
	bool isNumber(int pos); // check if value is number
};

#endif /* M4_H_ */
