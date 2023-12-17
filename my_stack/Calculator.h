#pragma once
#include <string>
#include <cmath>
#include "Tstack.h"
class TCalculator
{
	std::string  inf,postf;//инфиксная и постфиксная строки
	TStack<char> c=TStack<char>();// стек для операций
	TStack<double> d = TStack<double>();;// стек для чисел
public:
	TCalculator(std::string& str) :inf(str) { ToPostfix(); };
	bool CheckExpression();
private:
	
	int prioritet(char op)
	{
		if (op == '(' || op == ')')
			return 0;
		if (op == '+' || op == '-')
			return 1;
		if (op == '*' || op == '/')
			return 2;
		if (op == '^')
			return 3;
	}
	void ToPostfix();
public:
	double Calculation();
	void set_infix(std::string str);
	std::string get_postfix();
	std::string get_infix();
	double CalcPostfix();

};

