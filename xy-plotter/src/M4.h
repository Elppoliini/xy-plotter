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

class M4 {
public:
	M4();
	~M4()=default;
	std::string reply(std::vector<std::string> str_,struct Tasks *t);
	void execute();
};

#endif /* M4_H_ */
