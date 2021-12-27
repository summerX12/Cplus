#ifndef PENTAGONAL_H_
#define PENTAGONAL_H_

#include <iostream>
#include <vector>

#include "sequence.h"

using namespace std;

class Pentagonal : public num_sequence
{
public:
	Pentagonal(int len = 1, int beg_pos = 1) :_length(len), _beg_pos(beg_pos) {}

	virtual int elem(int pos) const;
	virtual const char* what_am_i() const { return "Pentagonal"; };
	virtual ostream& print(ostream &os = cout) const;

	virtual int length() { return _length; };
	virtual int beg_pos() { return _beg_pos; };

protected:
	int _length;
	int _beg_pos;
	virtual void gen_elems(int pos) const;
	static vector<int> _elems;
};



vector<int> Pentagonal::_elems;//////  import!!!!!!
int Pentagonal::elem(int pos) const
{
	if (!check_integrity(pos, _elems.size()))
		return 0;

	if (pos > _elems.size())
		Pentagonal::gen_elems(pos);

	return _elems[pos - 1];
}

void Pentagonal::gen_elems(int pos) const
{
	int i;

	for (i = _elems.size()+1; i <= pos; i++)
	{
		_elems.push_back(i*(3 * i - 1) / 2);
	}
}

ostream& Pentagonal::print(ostream &os) const
{
	int ix;
	int end_pos = _beg_pos - 1 + _length;

	if (end_pos > _elems.size())
		Pentagonal::gen_elems(end_pos);

	for (ix = _beg_pos - 1; ix < end_pos; ix++)
	{
		os << _elems[ix] << " ";
	}
	os << endl;

	return os;
}



#endif
