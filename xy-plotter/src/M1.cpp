/*
 * M1.cpp
 *
 *  Created on: 23 Sep 2020
 *      Author: johan
 */

#include "M1.h"

M1::M1() {
	// TODO Auto-generated constructor stub
}

bool M1::isNumber(int pos){
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

std::string M1::reply(std::vector<std::string> str_,struct Tasks *t){
	str = str_;
	if(isNumber(1) == true){
		int percent = (stoi(str[1])/(float)255)*100;
		pen_pwm_set(percent);
	}else{
		ITM_write("NOT NUMBER\r\n");
	}
	return "OK\r\n";
}



