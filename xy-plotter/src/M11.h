/*
 * M11.h
 *
 *  Created on: 23 Sep 2020
 *      Author: johan
 */

#ifndef M11_H_
#define M11_H_
#include <string>
#include <vector>
#include "Tasks.cpp"
#include "ITM_write.h"
#include "DigitalIoPin.h"

class M11 {
public:
	M11(){};
	~M11() = default;
	std::string reply(std::vector<std::string> str_,struct Tasks *t);
private:
	struct Tasks tempt;
	void checkStatus();
};


#endif /* M11_H_ */
