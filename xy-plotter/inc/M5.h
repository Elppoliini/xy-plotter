/*
 * M5.h
 *
 *  Created on: 23 Sep 2020
 *      Author: johan
 */

#ifndef M5_H_
#define M5_H_

#include <string>
#include <vector>
#include "Tasks.cpp"
#include "ITM_write.h"

class M5 {
public:
	M5();
	~M5()=default;
	std::string reply(std::vector<std::string> str_,struct Tasks *t); // // receive the incomming vector with commannds and save the direktion, area and speed.
private:
	std::vector<std::string> str;  // a vector where we can copy the incomming vector to
	bool isNumber(int pos); // check if value is number
	bool checkCommands(std::string letter, int pos); // check if the commands first letter is valid
};

#endif /* M5_H_ */
