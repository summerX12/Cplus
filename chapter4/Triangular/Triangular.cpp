#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

#include "Triangular.h"

using namespace std;

//Member Initialization List 成员初始化列表
Triangular::Triangular(int len, int beg_pos) : _length(len > 0 ? len : 1), _beg_pos(beg_pos > 0 ? beg_pos : 1)
{
	_next = _beg_pos;
	int elem_cnt = _beg_pos + _length;
	if (_elems.size() < elem_cnt)
	{
		gen_elements(elem_cnt);
	}
}
//Memberwise Initialization 成员逐一初始化
//以一个class object 作为另一个object的初值
Triangular::Triangular(const Triangular &rhs) : _length(rhs._length), _beg_pos(rhs._beg_pos), _next(rhs._next)
{
}

//copy constructor 代替default copy constructor
Triangular &Triangular::operator=(const Triangular &rhs)
{
	if (this != &rhs)
	{
		_length = rhs._length;
		_beg_pos = rhs._beg_pos;
		_next = 1;
	}
	return *this;
}

int Triangular::elem(int pos) const
{
	return _elems[pos - 1];
}

bool Triangular::next(int &value) const
{
	if (0 == _next)
		return false;

	if (_next < _beg_pos + _length)
	{
		value = _elems[_next++];
		return true;
	}
	_next = 0;
	return false;
}


///important ,  delete   will lead to error LINK2001
vector<int> Triangular::_elems;

bool Triangular::is_elem(int value)
{
	if (0 == _elems.size() || _elems[_elems.size() - 1] < value)
	{
		gen_elems_to_value(value);
	}
	return find(_elems.begin(), _elems.end(), value) != _elems.end();
}

//从当前位置开始，继续产生length个元素
void Triangular::gen_elements(int length)
{
	if (length <0 || length >_max_elems)
	{
		cerr << "Triangular invalid size" << endl;
		return;
	}
	if (_elems.size() < length)
	{
		int ix = _elems.size() ? _elems.size() + 1 : 1;
		while (ix <= length)
		{
			_elems.push_back(ix*(ix + 1) / 2);
			++ix;
		}
	}
	return;
}

void Triangular::gen_elems_to_value(int value)
{
	int ix = _elems.size();
	if (ix == 0)
	{
		_elems.push_back(1);
		ix++;
	}
	while (_elems[ix - 1] < value && ix < _max_elems)
	{
		_elems.push_back(ix*(ix + 1) / 2);
		++ix;
	}
	if (ix >= _max_elems)
	{
		cerr << "Triangular invalid size\n";
	}
	return;
}

void Triangular::display(int length, int beg_pos, ostream &os)
{
	int ix, elems;

	if (length <= 0 && beg_pos <= 0)
	{
		cerr << "display-----invalid parameter\n";
		return;
	}

	elems = beg_pos + length - 1;
	if (_elems.size() < elems)
	{
		gen_elements(elems);
	}

	for (ix = beg_pos; ix < elems; ix++)
	{
		os << _elems[ix] << " ";
	}
	return;
}



class iterator_overflow
{
};

inline void Triangular_iterator::check_integrity() const
{
	if (_index > Triangular::_max_elems)
	{
		throw iterator_overflow();
	}
	if (_index >= Triangular::_elems.size())
	{
		Triangular::gen_elements(_index);
	}
	return;
}


inline bool Triangular_iterator::operator==(const Triangular_iterator &rhs) const
{
	return _index == rhs._index;
}
//不加inline能成功执行，否则报错LNK2019
bool Triangular_iterator::operator!=(const Triangular_iterator &rhs) const
{
	return !(*this == rhs);
}

int Triangular_iterator::operator*() const
{
	check_integrity();
	return Triangular::_elems[_index];
}

Triangular_iterator &Triangular_iterator::operator++()
{
	++_index;
	check_integrity();
	return *this;
}

inline Triangular_iterator Triangular_iterator::operator++(int)
{
	Triangular_iterator tmp = *this;
	++_index;
	check_integrity();
	return tmp;
}

