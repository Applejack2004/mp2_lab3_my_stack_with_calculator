#include <string>
#include <iostream>
#include "Tstack.h"
#include "Calculator.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Запишите выражение : " << std::endl;
	std::string s;
	std::cin >> s;
	TCalculator a(s);
	bool check = a.CheckExpression();
	std::cout << s << "=" ;
	std::cout << a.CalcPostfix()<<std::endl;
	std::cout << s << "=" ;
	std::cout << a.Calculation() << std::endl;
	if (check == 1)
		std::cout << "The expression is correct" << std::endl;
	else
		std::cout << "The expression is incorrect" << std::endl;

}