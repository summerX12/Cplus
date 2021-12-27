#ifndef FIBONACCI_H_
#define FIBONACCI_H_

#include <iostream>
#include <vector>

#include "sequence.h"

using namespace std;

template <int len, int beg_pos=1>
class Fibonacci : public num_sequence<len, beg_pos>
{
public:
	Fibonacci() :num_sequence<len, beg_pos>( _elems) {};
	Fibonacci(const Fibonacci &rhs) : num_sequence(rhs) {};

protected:
	virtual void gen_elems(int pos) const;
	static vector<int> _elems;
};

template <int len, int beg_pos>
vector<int> Fibonacci<len, beg_pos>::_elems;//////  import!!!!!!

template <int len, int beg_pos>
void Fibonacci<len, beg_pos>::gen_elems(int pos) const
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
