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
/* Check limits */
class M11 {
public:
	M11(){};
	~M11() = default;
	std::string reply(std::vector<std::string> str_,struct Tasks *t); // receive the incomming vector with commannds and check the limit values
	bool checkLimYP(); // check lim1 returns true if limit is switch is open
	bool checkLimYM(); // check lim2
	bool checkLimXP(); // check lim3
	bool checkLimXM(); // check lim4
	void checkAllLim(); // wait that all limitswitches are open
private:
	struct Tasks tempt;


};


#endif /* M11_H_ */
