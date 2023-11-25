#pragma once
#include <algorithm>
#include <iostream>
template <class T>
class Tstack
{
	T* pMem;
	int max_size;
	int top;
public:
	Tstack& operator = (const Tstack& s)
	{
		if (*this == s)
		{
			return *this;
		}
		delete[] pMem;
		top = s.top;
		max_size = s.max_size;
		pMem = new T[s.max_size];
		std::copy(s.pMem, s.pMem + top, pMem);
		return *this;

	}
	~Tstack()
	{
		delete[] pMem;
	}
	Tstack( int _max_size=10)
	{
		if (_max_size < 1)
		{
			throw "bad size";
		}
		max_size = _max_size;
		pMem = new T[max_size];
		top = -1;
	}
	Tstack(const Tstack& s)
	{
		max_size = s.max_size;
		top = s.top;
		delete[]pMem;
		pMem = new T[max_size];

		for (int i = 0; i <= top; i++)
		{
			pMem[i] = s.pMem[i];
		}
	}
	bool Empty()
	{
		return top == -1;
	}
	bool Full()
	{
		return top == max_size - 1;
	}
	void Push(T elem)
	{
		if (top >= max_size-1)
		{
			throw("Stack Overflow");
		}
		pMem[top+1] = elem;
		top++;
	}
	T Pop()
	{
		if ( this->Empty()==true)
		{
			throw("Stack is empty");
		}
		top--;
		return pMem[top+1];
	}
	int get_top()
	{
		return top;
	}
	T TOP()
	{
		if (top == -1)
			throw ("Stack is empty");
		return pMem[top];
	}
	void Clear()
	{
		while (!this->Empty())
		{
			this->Pop();
		}
	}
	void Output()
	{
		if (top == -1)
		{
			std::cout << "stack is empty" << std::endl;
		}
		std::cout << '(';
		for (int i = 0; i <= top; i++)
		{
			std::cout << pMem[i] << "";

		}
		std::cout <<")"<<std::endl;
	}

};

