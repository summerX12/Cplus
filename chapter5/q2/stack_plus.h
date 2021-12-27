#ifndef STACK_PLUS_H_
#define STACK_PLUS_H_

#include <iostream>
#include <vector>

using namespace std;

class Stack
{
public:
	Stack(int len) :_length(len) {};
	virtual ~Stack() {};
	bool pop();
	bool push(int elem);
	int size() const { return _length; };
	bool empty() const { return _relems.empty(); };
	bool full() const { return _relems.size() == _length ? true : false; };
	virtual int peek(int pos) const = 0;
	ostream& print(ostream &os = cout) const ;

protected:
	int _length;
	vector<int> _relems;
};



bool Stack::push(int elem)
{
	if (_relems.size() == _length)
		return false;

	_relems.push_back(elem);
	return true;
}

bool Stack::pop()
{
	if (_relems.empty())
		return false;

	_relems.pop_back();
	return true;
}

ostream& Stack::print(ostream &os) const
{
	int i;

	for (i = 0; i < _relems.size(); i++)
	{
		os << _relems[i] << " ";
	}
	os << endl << endl;

	return os;
}

ostream &operator<<(ostream &os, const Stack &ns)
{
	return ns.print(os);
}

#endif
