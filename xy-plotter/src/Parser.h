/*
 * Parser.h
 *
 *  Created on: 22 Sep 2020
 *      Author: johan
 */

#ifndef PARSER_H_
#define PARSER_H_
#include <string>
#include <vector>
#include "Tasks.cpp"

class Parser {
public:
	Parser();
	virtual ~Parser();
	void read(char *str_);
	std::vector<std::string> getCommandLine();
	void reply();
	void firstComand();
private:
	struct Tasks t;
	std::string str;
	std::vector<std::string> commands;
	void divideString();
	void print();

};

#endif /* PARSER_H_ */
