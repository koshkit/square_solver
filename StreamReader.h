#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <deque>


enum state {
	initialState = 0,
	positiveNumber = 1,
	negativeNumber = 2
};

class StreamReader
{
public:
	StreamReader();
	~StreamReader();
	void startParse(std::ifstream & input, std::shared_ptr<std::deque<std::string>> equationDeque);

private:
	char _c;
	std::string _param;
};

