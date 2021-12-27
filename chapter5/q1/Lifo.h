#ifndef LIFO_H_
#define LIFO_H_

#include <iostream>
#include <vector>

#include "stack.h"

using namespace std;

class Lifo:public Stack
{
public:
	Lifo(int len) : _length(len) {};

	virtual bool pop();
	virtual bool push(int elem) ;
	virtual int size() const { return _length; };
	virtual bool empty() const { return _elems.empty(); };
	virtual bool full() const { return _elems.size() == _length ? true : false; };
	virtual int peek() const { return _elems[_elems.size() - 1]; };
	virtual ostream& print(ostream &os = cout) const;

protected:
	int _length;
	vector<int> _elems;

};

bool Lifo::pop()
{
	if (empty())
		return false;

	 _elems.pop_back(); 
	 return true;
}

bool Lifo::push(int elem)
{
	if (full())
		return false;

	_elems.push_back(elem); 
	return true;
}

ostream& Lifo::print(ostream &os) const
{
	int i;

	for (i = 0; i < _elems.size(); i++)
	{
		os << _elems[i] << " ";
	}
	os <<endl<< endl;

	return os;
}
#endif



