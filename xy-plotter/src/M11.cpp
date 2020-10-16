/*
 * M11.cpp
 *
 *  Created on: 23 Sep 2020
 *      Author: johan
 */

#include "M11.h"

/* Check the status of limit switches */
bool M11::checkLimYP()
{
	DigitalIoPin lim1(0,9,DigitalIoPin::pullup,true);
	if(!lim1.read() == true)
	{
		tempt.limYP = true;
		return true;
	}else if(!lim1.read() == false)
	{
		tempt.limYP = false;
	}
	return false;
}

bool M11::checkLimYM()
{
	DigitalIoPin lim2(0,29,DigitalIoPin::pullup,true);
	if(!lim2.read() == true)
	{
		tempt.limYM = true;
		return true;
	}else if(!lim2.read() == false)
	{
		tempt.limYM = false;
	}
	return false;
}

bool M11::checkLimXP()
{
	DigitalIoPin lim3(0, 0, DigitalIoPin::pullup, true);
	if(!lim3.read() == true)
	{
		tempt.limXP = true;
		return true;
	}else if(!lim3.read() == false){
		tempt.limXP = false;
	}
	return false;
}

bool M11::checkLimXM()
{
	DigitalIoPin lim4(1, 3, DigitalIoPin::pullup, true);
	if(!lim4.read() == true)
	{
		tempt.limXM = true;
		return true;
	}else if(!lim4.read() == false)
	{
		tempt.limXM = false;
	}
	return false;
}
void M11::checkAllLim()
{
	while(checkLimYP() != true || checkLimYM() != true || checkLimXM() != true || checkLimXP() != true ){

	}

}

std::string M11::reply(std::vector<std::string> str_,struct Tasks *t){
	tempt = *t;

	checkLimYP();
	checkLimYM();
	checkLimXP();
	checkLimXM();

	t->limXM = tempt.limXM ;
	t->limXP = tempt.limXP;
	t->limYM = tempt.limYM;
	t->limYP = tempt.limYP;

	char buffer[50];
	sprintf( buffer," M 11 %d %d %d %d\r\nOK\r\n", t->limYP,t->limYM,t->limXP,t->limXM);
	std::string str = buffer;
	ITM_write(str.c_str());
	return str;
}


