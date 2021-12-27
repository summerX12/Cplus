#ifndef FIBONACCI_H_
#define FIBONACCI_H_

#include <iostream>
#include <vector>

#include "sequence.h"

using namespace std;

class Fibonacci : public num_sequence
{
public:
//	Fibonacci(int len = 1, int beg_pos = 1) :num_sequence(len, beg_pos, &_elems) {};
	Fibonacci(int len = 1, int beg_pos = 1) :num_sequence(len, beg_pos, _elems) {};
	Fibonacci(const Fibonacci &rhs) : num_sequence(rhs) {};
	virtual const char* what_am_i() const { return "Fibonacci"; };
protected:
	virtual void gen_elems(int pos) const;
	static vector<int> _elems;
};


vector<int> Fibonacci::_elems;//////  import!!!!!!

void Fibonacci::gen_elems(int pos) const
{
	if (_elems.empty())
	{
		_elems.push_back(1);
		_elems.push_back(1);
	}
	while (_elems.size() <= pos)
	{
		_elems.push_back(_elems[_elems.size() - 2] + _elems[_elems.size() - 1]);
	}
}


#endif
