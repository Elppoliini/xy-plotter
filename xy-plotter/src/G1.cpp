/*
 * G1.cpp
 *
 *  Created on: 23 Sep 2020
 *      Author: johan
 */

#include "G1.h"

G1::G1() {
	// TODO Auto-generated constructor stub
}
void plotLineLow(double x0, double x1, double y0, double y1){

}

bool G1::isNumber(int pos){
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
		ITM_write(" G1 nr failed! \r\n");
		return false;
	}
}

bool G1::checkCommands(std::string letter,int pos){

	int check =0;
	for(int i=0;i<(int)letter.length();i++){
		if(str[pos][i] == letter[check])
		{
			check++;
		}
	}
	if(check == (int)letter.length())
	{
		str[pos].erase(0,letter.length());
		return true;
	}
	ITM_write("M2 letter failed\r\n");
	return false ;
}

std::string G1::reply(std::vector<std::string> str_,struct Tasks *t){
	str = str_;
	tempt = *t;
	if(checkCommands("X",1) == true && isNumber(1) == true){
		t->xCord = atof(str[1].c_str());
		double steps = (t->xCord)/(t->stepsize);
		t->x1 = steps;
	}
	if(checkCommands("Y",2) == true && isNumber(2) == true){
		t->yCord = atof(str[2].c_str());
		double steps = (t->yCord)/(t->stepsize);
		t->y1 = steps;
		ITM_write("Ycord: ");
		ITM_write(std::to_string(t->yCord).c_str());
		ITM_write("\r\n");
		ITM_write("stepsize: ");
		ITM_write(std::to_string(t->stepsize).c_str());
		ITM_write("\r\n");
		ITM_write("y1: ");
		ITM_write(std::to_string(t->y1).c_str());
		ITM_write("\r\n");
	}

	return "OK\r\n";

}


