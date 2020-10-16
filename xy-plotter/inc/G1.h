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
#include "M11.h"
#include "ITM_write.h"
#include "SpeedSettings.h"

class G1 {
public:
	G1();
	~G1()=default;
	std::string reply(std::vector<std::string> str_,struct Tasks *t);
	bool checkCommands(std::string letter,int pos);
	bool isNumber(int pos);
	void plotLineLow(double x0, double x1, double y0, double y1);
private:
	struct Tasks tempt;
	std::vector<std::string> str;

};

#endif /* G1_H_ */
