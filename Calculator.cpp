#include "pch.h"
#include <windows.h>
#include "Calculator.h"


/*
* Calculate and print out fromated result to standard output
*/
template<class A, class B, class C>
auto Calculator::calculateDiscriminant(A a, B b, C c)
{
	return (std::pow(b, 2) - 4 *a * c);
}

template<class A, class B, class C>
void Calculator::calculateRoots(A a, B b, C c)
{
	auto d = calculateDiscriminant(a, b, c);
	if (d < 0) {
		printRoots(a, b, c);
	}
	else if (d > 0) {
		auto x1 = (-b + std::sqrt(d) ) / (2 * a);
		auto x2 = (-b - std::sqrt(d) ) / (2 * a);
		printRoots(a, b, c, x1,x2);
	}
	else {
		auto x1 = (-b) / (2 * a);
		auto x2 = (-b) / (2 * a);
		printRoots(a, b, c, x1, x2);
	}
}

template<class A, class B, class C>
void Calculator::calculate(A a, B b, C c)
{
	if(a == 0) {
		auto x = -(b / c);
		printRoots(a, b, c, x);
	}
	else {
		calculateRoots(a, b, c);
	}
}

void Calculator::getNumbers(const std::string &str)
{
	std::string tmp;
	int k = 0;
	_a, _b, _c = 0;
	for (int i = 0; i < str.length(); ++i) {		
		if (str[i] == ' ' || i == str.length()) {
			switch (k) {
				case 0: {
					_a = stoi(tmp);
					tmp.clear();
					break;
				}
				case 1: {
					_b = stoi(tmp);
					tmp.clear();
					break;
				}
				case 2: {
					_c = stoi(tmp);
					tmp.clear();
					k = 0;
					break;
				}
			}
			k++;
		}
		else {
			tmp += str[i];
		}		
	}
	calculate(_a, _b, _c);
}

template<class A, class B, class C>
inline void Calculator::printRoots(A a, B b, C c)
{
	std::cout << "(" << a << " " << b << " " << c << ")" << " => " << "no roots" << std::endl;
}

template<class A, class B, class C, class X>
void Calculator::printRoots(A a, B b, C c, X x1)
{
	std::cout << "(" << a << " " << b << " " << c << ")" << " => " << "(" << x1 << ")" << std::endl;
}

template<class A, class B, class C, class X, class X1>
void Calculator::printRoots(A a, B b, C c, X x1, X1 x2)
{
	std::cout << "(" << a << " " << b << " " << c << ")" << " => " << "(" << x1 << ", "<< x2 << ")" << std::endl;
}

void Calculator::start(std::shared_ptr<std::deque<std::string>> shr_ptr)
{
	doWaitData = true;
	while (doWaitData) {
		if (!shr_ptr->empty()) {
			std::deque<std::string>::iterator it = shr_ptr->end() - 1;
			for (it;  it != shr_ptr->begin(); it--) {
				//std::cout << ' ' << (it)->data() << std::endl;
				getNumbers((it)->data());
			}
			//std::cout << ' ' << (it)->data() << std::endl;
			getNumbers((it)->data());
			shr_ptr->erase(it + 1, shr_ptr->end());
			if (std::distance(it, shr_ptr->begin()) < 1) {
				doWaitData = false;
			}
		}
		else
		{
			Sleep(100);
		}
	}
}
