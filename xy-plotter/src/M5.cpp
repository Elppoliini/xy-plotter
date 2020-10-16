/*
 * M5.cpp
 *
 *  Created on: 23 Sep 2020
 *      Author: johan
 */

#include "M5.h"

M5::M5() {
	// TODO Auto-generated constructor stub
}

bool M5::isNumber(int pos){
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
		ITM_write(" M2 nr failed! \r\n");
		return false;
	}
}

bool M5::checkCommands(std::string letter,int pos){

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

std::string M5::reply(std::vector<std::string> str_,struct Tasks *t){
	str = str_;
	if(checkCommands("A",1) == true && isNumber(1) == true){
		t->direktionX = stoi(str[1]);
	}
	if(checkCommands("B",2) == true && isNumber(2) == true){
		t->directionY = stoi(str[2]);
	}
	if(checkCommands("H",3) == true && isNumber(3) == true){
		t->height = stoi(str[3]);
	}
	if(checkCommands("W",4) == true && isNumber(4) == true){
		t->width = stoi(str[4]);
	}
	if(checkCommands("S",5) == true && isNumber(5) == true){
		t->speed = stoi(str[5]);
	}
	return "OK\r\n";
}


