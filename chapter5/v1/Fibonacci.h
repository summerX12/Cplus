#ifndef FIBONACCI_H_
#define FIBONACCI_H_

#include <iostream>
#include <vector>

#include "sequence.h"

using namespace std;

class Fibonacci : public num_sequence
{
public:
	Fibonacci(int len = 1, int beg_pos = 1) :_length(len), _beg_pos(beg_pos) {}

	virtual int elem(int pos) const;
	virtual const char* what_am_i() const { return "Fibonacci"; };
	virtual ostream& print(ostream &os = cout) const;

	virtual int length() { return _length; };
	virtual int beg_pos() { return _beg_pos; };

protected:
	int _length;
	int _beg_pos;
	virtual void gen_elems(int pos) const;
	static vector<int> _elems;
};



vector<int> Fibonacci::_elems;//////  import!!!!!!
int Fibonacci::elem(int pos) const
{
	if (!check_integrity(pos, _elems.size()))
		return 0;

	if (pos > _elems.size())
		Fibonacci::gen_elems(pos);

	return _elems[pos - 1];
}

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

ostream& Fibonacci::print(ostream &os) const
{
	int ix;
	int end_pos = _beg_pos - 1 + _length;

	if (end_pos > _elems.size())
		Fibonacci::gen_elems(end_pos);

	for (ix = _beg_pos - 1; ix < end_pos; ix++)
	{
		os << _elems[ix] << " ";
	}
	os << endl;

	return os;
}

/*
inline bool Fibonacci::check_integrity(int pos,int size) const
{
	if (!num_sequence::check_integrity(pos))
		return false;

	if (pos > _elems.size())
		Fibonacci::gen_elems(pos);

	return true;
}
*/


#endif
