/*
 * G28.h
 *
 *  Created on: 23 Sep 2020
 *      Author: johan
 */

#ifndef G28_H_
#define G28_H_

#include <string>
#include <vector>
#include "Tasks.cpp"
#include "ITM_write.h"
#include "SpeedSettings.h"
#include "M11.h"

class G28 {
public:
	G28();
	~G28()=default;
	void go_to_origo();
	std::string reply(std::vector<std::string> str_,struct Tasks *t);
};

#endif /* G28_H_ */
