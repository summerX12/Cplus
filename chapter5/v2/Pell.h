#ifndef PELL_H_
#define PELL_H_

#include <iostream>
#include <vector>

#include "sequence.h"

using namespace std;

class Pell : public num_sequence
{
public:
//	Pell(int len = 1, int beg_pos = 1) :num_sequence(len, beg_pos, &_elems) {};
	Pell(int len = 1, int beg_pos = 1) :num_sequence(len, beg_pos, _elems) {};
	Pell(const Pell &rhs) :num_sequence(rhs) {};
	virtual const char* what_am_i() const { return "Pell"; };
protected:
	virtual void gen_elems(int pos) const;
	static vector<int> _elems;
};



vector<int> Pell::_elems;//////  import!!!!!!

void Pell::gen_elems(int pos) const
{
	if (_elems.empty())
	{
		_elems.push_back(1);
		_elems.push_back(2);
	}
	while (_elems.size() <= pos)
	{
		_elems.push_back(_elems[_elems.size() - 2] + 2*_elems[_elems.size() - 1]);
	}
}


#endif
