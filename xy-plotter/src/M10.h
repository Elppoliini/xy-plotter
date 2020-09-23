/*
 * M10.h
 *
 *  Created on: 23 Sep 2020
 *      Author: johan
 */

#ifndef M10_H_
#define M10_H_
#include <string>
#include <vector>
#include "Tasks.cpp"
#include "ITM_write.h"

class M10 {
public:
	M10();
	~M10() = default;
	std::string reply(std::vector<std::string> str_,struct Tasks *t);
	void execute();
private:

};

#endif /* M10_H_ */
