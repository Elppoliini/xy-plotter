/*
 * M1.h
 *
 *  Created on: 23 Sep 2020
 *      Author: johan
 */

#ifndef M1_H_
#define M1_H_
#include <string>
#include <vector>
#include "Tasks.cpp"
#include "ITM_write.h"

class M1 {
public:
	M1();
	~M1()=default;
	std::string reply(std::vector<std::string> str_,struct Tasks *t);
	void execute();
};

#endif /* M1_H_ */
