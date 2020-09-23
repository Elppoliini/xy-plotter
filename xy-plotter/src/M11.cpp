/*
 * M11.cpp
 *
 *  Created on: 23 Sep 2020
 *      Author: johan
 */

#include "M11.h"


/* Check the status of limit switches */
void M11::checkStatus(){
	DigitalIoPin lim1(0,9,DigitalIoPin::pullup,true);
	DigitalIoPin lim2(0,29,DigitalIoPin::pullup,true);
	DigitalIoPin lim3(0, 0, DigitalIoPin::pullup, true);
	DigitalIoPin lim4(1, 3, DigitalIoPin::pullup, true);

	if(!lim1.read() == true){
		tempt.limYP = true;
	}else if(!lim1.read() == false){
		tempt.limYM = false;
	}

	if(!lim2.read() == true){
		tempt.limYM = true;
	}else if(!lim2.read() == false){
		tempt.limYM = false;
	}

	if(!lim3.read() == true){
		tempt.limXP = true;
	}else if(!lim3.read() == false){
		tempt.limXP = false;
	}

	if(!lim4.read() == true){
		tempt.limXM = true;
	}else if(!lim4.read() == false){
		tempt.limXM = false;
	}

}

std::string M11::reply(std::vector<std::string> str_,struct Tasks *t){
	tempt = *t;
	checkStatus();
	t->limXM = tempt.limXM ;
	t->limXP = tempt.limXP;
	t->limYM = tempt.limYM;
	t->limYP = tempt.limYP;

	int lenght = 50;
	char buffer[lenght];
	int count = snprintf ( buffer, lenght, "M11 %d %d %d %d\r\nOK\r\n", t->limYP,t->limYM,t->limXP,t->limXM);
	if(count > 0 && count < lenght){
		std::string str = buffer;
		return str;
	}
	return " \r\n";
}


