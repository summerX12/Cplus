#ifndef LIFO_PLUS_H_
#define LIFO_PLUS_H_

#include <iostream>
#include <vector>

#include "stack_plus.h"

using namespace std;

class Lifo: public Stack
{
public:
	Lifo(int len) : Stack(len) {};
	virtual ~Lifo() {};
	virtual int peek(int pos) const { return 0; };
//private:
//	static vector<int> _elems;
};


class Peek : public Stack
{
public:
	Peek(int len) : Stack(len) {};
	virtual ~Peek() {};
	virtual int peek(int pos) const ;
//private:
//	vector<int> _relems;
};

int Peek::peek(int pos) const
{
	if (empty() || pos <= 0 || pos > _relems.size())
		return 0;
	return _relems[pos - 1];
}


#endif
