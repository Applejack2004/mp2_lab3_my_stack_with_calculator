#include <string>
#include <iostream>
#include "Tstack.h"
#include "Calculator.h"
int main()
{
	std::string s = "(2+2)*2^2";
	TCalculator a(s);
	bool check = a.CheckExpression();
	std::cout << a.CalcPostfix()<<std::endl;
	std::cout <<  check;
}