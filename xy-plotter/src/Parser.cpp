/*
 * Parser.cpp
 *
 *  Created on: 22 Sep 2020
 *      Author: johan
 */

#include "Parser.h"
#include "ITM_write.h"

#include "M1.h"
#include "M2.h"
#include "M4.h"
#include "M5.h"
#include "M10.h"
#include "M11.h"
#include "G1.h"
#include "G28.h"

/*******************************************
 * Constructor and destructor
 *******************************************/

Parser::Parser() {
	// TODO Auto-generated constructor stub
}

Parser::~Parser() {
	// TODO Auto-generated destructor stub
}

/*******************************************
 * Public class functions
 *******************************************/

void Parser::read(const char* str_) {
	str = str_;
	divideString();
	print();
}

std::vector<std::string> Parser::getCommandLine(){
	return commands;
}

std::string Parser::reply(){
	t.command = commands[0];
	std::string rply;

	if(commands[0]== "G28")
	{
		G28 g28;
		rply = g28.reply(commands,&t);
	}else if(commands[0] == "G1")
	{
		G1 g1;
		if(firstTime == 0){
			firstTime++;
			t.stepsize = (t.width/(double)steps);
			ITM_write("Steps:");
			ITM_write(std::to_string(t.stepsize).c_str());
			ITM_write("\r\n");
		}
		rply = g1.reply(commands,&t);
	}else if(commands[0] == "M1")
	{
		M1 m1;
		rply = m1.reply(commands,&t);
	}else if(commands[0]== "M2")
	{
		M2 m2;
		rply = m2.reply(commands,&t);
	}else if(commands[0] == "M4")
	{
		M4 m4;
		rply = m4.reply(commands,&t);
	}else if(commands[0] == "M5")
	{
		M5 m5;
		rply = m5.reply(commands,&t);
	}else if(commands[0] == "M10")
	{
		M10 m10;
		rply = m10.reply(commands,&t);
	}else if(commands[0]== "M11")
	{
		M11 m11;
		rply = m11.reply(commands,&t);
	}else
	{
		rply = "OK\r\n";
	}

	//ITM_write(rply.c_str());
	return rply;
}

/***********************************************
 * Private class functions
 ***********************************************/

void Parser::divideString(){
	/* check that the code includes only one line change other = garbage */
	commands.clear();
	size_t pos = 0;
	std::string tempStr;
	std::string token;
	if((pos = str.find('\n')) != std::string::npos) {
		str = str.substr(0, pos);
	}
	/*  Divide the string by space and add it to a vector and remove all extra spaces */
	tempStr = str;
	pos = 0;
	while ((pos = tempStr .find(' ')) != std::string::npos) {
		token = tempStr .substr(0, pos);
		tempStr.erase(0, pos + 1);
		token.erase(remove(token.begin(), token.end(), ' '), token.end());
		commands.push_back(token);
	}
	tempStr.erase(remove(tempStr.begin(), tempStr.end(), ' '), tempStr.end());
	commands.push_back(tempStr);
}

void Parser::print(){
	for (auto i = commands.begin(); i != commands.end(); ++i){
		std::string temp= *i;
		ITM_write(temp.c_str());
		ITM_write(" ");
	}
	ITM_write("\n");
}

void Parser::calibration()
{
	int countY = 0, sumY = 0;
	M11 m11;
	G28 g28;
	m11.checkAllLim();
	g28.go_to_origo();
	while(m11.checkLimYM() == true)
	{
		RIT_start(2,1000000/(1000*2),true,true);
		countY++;
	}
	sumY += countY;
	countY = 0;
	while(m11.checkLimYP() == true)
	{
		RIT_start(2,1000000/(1000*2),true,false);
		countY++;
	}
	sumY += countY;
	countY = 0;

	int totalY = sumY/2;
	steps = totalY;
	ITM_write("steps: ");
	ITM_write(std::to_string(steps).c_str());
	ITM_write("\r\n");
}
