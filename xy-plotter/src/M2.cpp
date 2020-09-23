/*
 * M2.cpp
 *
 *  Created on: 23 Sep 2020
 *      Author: johan
 */

#include "M2.h"

M2::M2() {
	// TODO Auto-generated constructor stub

}
bool M2::isNumber(int pos){
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

bool M2::checkCommands(std::string letter,int pos){

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

std::string M2::reply(std::vector<std::string> str_,struct Tasks *t){
	str = str_;

	if(checkCommands("U",1) == true && isNumber(1) == true){
		t->penUp = stoi(str[1]);
	}

	if(checkCommands("D",2) == true && isNumber(2) == true){
		t->penDown = stoi(str[2]);
	}
	return "OK\r\n";


}

