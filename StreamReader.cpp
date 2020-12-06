#include "pch.h"
#include "StreamReader.h"

/*
* Equation params store in deque
* for constant complexity data access
*/

StreamReader::StreamReader()
{
	_param = "";
}

StreamReader::~StreamReader()
{
}

void StreamReader::startParse(std::ifstream & input, std::shared_ptr<std::deque<std::string>> equationDeque)
{
	int count = 0;
	int i = state::initialState;
	while (input.get(_c)) {
		switch (i) {
		case state::initialState: {
			if (isdigit(_c)) {
				_param += _c;
				i = state::positiveNumber;
			}
			else if (_c == '-') {
				_param += _c;
				i = state::negativeNumber;
			}

			break;
		}
		case state::positiveNumber: {
			if (isdigit(_c)) {
				_param += _c;
			}
			else if (!isdigit(_c)) {
				++count;
				_param += " ";
				i = state::initialState;
			}
			break;
		}
		case state::negativeNumber: {
			if (isdigit(_c) || _c == '.') {
				_param += _c;
			}
			else if (!isdigit(_c)) {
				++count;
				_param += " ";
				i = state::initialState;
			}
			break;
		}
		default: break;
		}
		if (count == 3) {
			equationDeque->push_front(_param);
			_param.clear();
			count = 0;
		}
					
	}
	equationDeque->push_front(_param);
	_param.clear();
	input.close();	
}
