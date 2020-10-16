/*
 * M2.h
 *
 *  Created on: 23 Sep 2020
 *      Author: johan
 */

#ifndef M2_H_
#define M2_H_
#include <string>
#include <vector>
#include "Tasks.cpp"
#include "ITM_write.h"
#include <algorithm>

/* Class for Saving pen position values */
class M2 {
public:
	M2();
	~M2() = default;
	std::string reply(std::vector<std::string> str_,struct Tasks *t); // receive the incomming vector with commannds and saving the pen position
private:
	std::vector<std::string> str; // a vector where we can copy the incomming vector to
	bool isNumber(int pos); // check if value is number
	bool checkCommands(std::string letter, int pos); // check if the commands first letter is valid
};

#endif /* M2_H_ */
