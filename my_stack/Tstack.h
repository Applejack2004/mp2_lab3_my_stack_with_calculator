#pragma once
#include <algorithm>
#include <iostream>
template <class T>
struct TNode
{
	T val;
	TNode <T>* pNext;
};
template<class T>
class TStack
{
	TNode<T>* pFirst;
public:
	TStack()
	{ 
		pFirst = NULL; 
	}

	TStack(const TStack<T>& a);
	TStack& operator=(const TStack& a);
	void Clear();
	bool Empty() 
	{ 
		return pFirst == NULL; 
	}
	void Push(T a);
	T Top();
	T Pop();
	~TStack();
	bool Full();
	int GetNum();
};
template<class T>
TStack<T>::TStack(const TStack<T>& a)
{
	TNode<T>* tmp = new TNode<T>;
	tmp = a.pFirst;
	while (tmp != NULL)
	{
		pFirst = tmp;
		tmp = tmp->pNext;
	}

}
template<class T>
TStack<T>& TStack<T>:: operator=(const TStack& a)
{
	TNode<T>* tmp = new TNode<T>;
	tmp = a.pFirst;
	while (tmp != NULL)
	{
		pFirst = tmp;
		tmp = tmp->pNext;
	}
	return *this;
}
template<class T>
void TStack<T>::Clear()
{
	TNode <T>* tmp = pFirst;
	while (pFirst != NULL)
	{
		pFirst = pFirst->pNext;
		delete tmp;
		tmp = pFirst;
	}
}
template<class T>
void TStack<T>::Push(T a)
{
	TNode <T>* TMP;
	TMP = new TNode<T>;
	TMP->pNext = pFirst;
	TMP->val = a;
	pFirst = TMP;
}
template<class T>
T TStack<T>::Top()
{
	if (Empty())
		throw "error";
	return pFirst->val;
}
template<class T>
T TStack<T>::Pop()
{
	if (Empty())
		throw "error";
	T res = pFirst->val;
	TNode<T>* tmp = pFirst;
	pFirst = pFirst->pNext;
	delete tmp;
	return res;
}
template<class T>
TStack<T>::~TStack()
{
	TNode <T>* tmp = pFirst;
	while (pFirst != NULL)
	{
		pFirst = pFirst->pNext;
		delete tmp;
		tmp = pFirst;
	}
}
template<class T>
bool TStack<T>::Full()
{
	TNode<T>* p = new TNode<T>;
	if (p)
	{
		delete p;
		return true;
	}
	else
	{
		return false;
	}
}
template<class T>
int TStack<T>::GetNum()
{
	TNode<T>* p = pFirst;
	int i = 0;
	while (p != NULL)
	{
		i++;
		p = (*p).pNext;
	}
	return i;
}



