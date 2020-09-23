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


class M2 {
public:
	M2();
	~M2()=default;
	std::string reply(std::vector<std::string> str_,struct Tasks *t);
private:
	std::vector<std::string> str;
	bool isNumber(int pos);
	bool checkCommands(std::string letter, int pos);
};

#endif /* M2_H_ */
