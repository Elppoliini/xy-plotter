/*
 * M4.cpp
 *
 *  Created on: 23 Sep 2020
 *      Author: johan
 */

#include "M4.h"

M4::M4() {
	// TODO Auto-generated constructor stub
}

bool M4::isNumber(int pos){
	int count=0;

	for(int i = 0; i< (int)str[pos].length(); i++)
	{
		if(isdigit((int)str[pos][i])!=0 || (int)str[pos][i]== '.'|| (int)str[pos][i]== '-'){
			count++;
		}
	}
	if(count == (int)str[pos].length())
	{
		return true;
	}else
	{
		ITM_write(" M1 nr failed! \r\n");
		return false;
	}
	return false;
}

std::string M4::reply(std::vector<std::string> str_,struct Tasks *t){
	str = str_;
	if(isNumber(1) == true){
		int percent = (stoi(str[1])/(float)255)*100;
		laser_pwm_set(percent);
	}else{
		ITM_write("NOT NUMBER\r\n");
	}
	return "OK\r\n";
}


