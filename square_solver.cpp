#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Calculator.h"
#include "StreamReader.h"


/*
* The program reads data from eq_params.txt file input stream, 
* eliminates nondigit symbols.
* To speed up calculation parrallel thread used 
*/
int main()
{
	StreamReader streamParser;
	Calculator calculator;

	std::ifstream input("eq_params.txt");

	if (input.is_open()) {
		std::deque<std::string> _equationDeque;
		std::shared_ptr<std::deque<std::string>> shr_ptr = std::make_shared<std::deque<std::string>>(_equationDeque);

		std::thread calculateThread(&Calculator::start, &calculator, shr_ptr);

		streamParser.startParse(input, shr_ptr);		

		calculateThread.join();
	}
	else {
		std::cout << "Can't find or open data file." << "\n";
	}

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
