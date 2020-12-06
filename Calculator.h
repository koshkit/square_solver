#pragma once
#include <iostream>
#include <array>
#include <math.h>
#include <deque>
#include <stdio.h> 
#include <string>
#include <thread>

class Calculator
{
public:

	void start(std::shared_ptr<std::deque<std::string>> shr_ptr);
	
	Calculator() {
		isCalculateThreadRuns = false;
		doWaitData = false;
	};

	~Calculator() {
	};

	template<class A, class B, class C>
	void calculate(A a, B b, C c);

private:
	bool isCalculateThreadRuns;
	bool doWaitData;

	int _a, _b, _c;


	std::shared_ptr<std::deque<std::string>> _dequePointer;

	void getNumbers(const std::string & str);

	template<class A, class B, class C>
	auto calculateDiscriminant(A a, B b, C c);

	template<class A, class B, class C>
	void calculateRoots(A a, B b, C c);

	template<class A, class B, class C>
	void printRoots(A a, B b, C c);

	template<class A, class B, class C, class X>
	void printRoots(A a, B b, C c, X x1);

	template<class A, class B, class C, class X, class X1>
	void printRoots(A a, B b, C c, X x1, X1 x2);
};