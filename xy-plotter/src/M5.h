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
	std::string reply(std::vector<std::string> str_,struct Tasks *t);


private:
	std::vector<std::string> str;
	bool isNumber(int pos);
	bool checkCommands(std::string letter, int pos);
};

#endif /* M5_H_ */
