/*
 * G1.h
 *
 *  Created on: 23 Sep 2020
 *      Author: johan
 */

#ifndef G1_H_
#define G1_H_

#include <string>
#include <vector>
#include "Tasks.cpp"
#include "ITM_write.h"

class G1 {
public:
	G1();
	~G1()=default;
	std::string reply(std::vector<std::string> str_,struct Tasks *t);
		void execute();
};

#endif /* G1_H_ */