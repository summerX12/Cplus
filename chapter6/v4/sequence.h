#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

template <void(*pf)(int pos, vector<int> &seq)>
class numeric_sequence
{
public:
	numeric_sequence(int len, int beg_pos = 1)
	{
		_len = len > 0 ? len : 1;
		_beg_pos = beg_pos > 0 ? beg_pos : 1;
		pf(beg_pos + len - 1, _elems);
	}

	ostream & print(ostream& os = cout) const;
private:
	int _len;
	int _beg_pos;
	vector<int> _elems;
};

template <void(*pf)(int pos, vector<int> &seq)>
ostream & numeric_sequence<pf>
::print(ostream &os) const
{
	int i;
	for (i = 0; i < _elems.size(); i++)
	{
		os << _elems[i] << " ";
	}
	return os;
}

template <void(*pf)(int pos, vector<int> &seq)>
ostream &operator<<(const ostream &os, const numeric_sequence<pf> &ns)
{
	return ns.print();
}



template <int len,int beg_pos>
class num_sequence
{
public:
	virtual ~num_sequence() {};
	const char* what_am_i() const ;
	int elem(int pos) const;
	ostream& print(ostream &os = cout) const;	
	static int max_elems() { return 64; };
	
	static void display(ostream &os, const num_sequence &ns, int pos);

protected:
	virtual void gen_elems(int pos) const = 0 ;//´¿Ðéº¯Êý
	bool check_integrity(int pos,int size) const;

	num_sequence(vector<int> &re=0): _relems(re) {};
	vector<int> & _relems;
};

template <int length, int beg_pos>
inline const char* num_sequence<length,beg_pos>::
what_am_i() const
{
	return typeid(*this).name();
}

template <int len, int beg_pos>
bool num_sequence<len, beg_pos>::check_integrity(int pos, int size) const
{
	if (pos < 0 || pos > 64)
	{
		cerr << "invalid position\n";
		return false;
	}

	if (pos > size)
		gen_elems(pos);

	return true;
}

template <int len, int beg_pos>
int num_sequence<len, beg_pos>::elem(int pos) const
{
	if (!check_integrity(pos, _relems.size()))
		return 0;
	return _relems[pos - 1];
}

template <int len, int beg_pos>
ostream& num_sequence<len, beg_pos>::print(ostream &os) const
{
	int ix;
	int end_pos = beg_pos - 1 + len;

	if (!check_integrity(end_pos, _relems.size()))
	{
		return os;
	}

	for (ix = beg_pos - 1; ix < end_pos; ix++)
	{
		os << _relems[ix] << " ";
	}
	os << endl;

	return os;
}

template <int len, int beg_pos>
ostream &operator<<(ostream &os, const num_sequence<len, beg_pos> &ns)
{
	return ns.print(os);
}

template <int len, int beg_pos>
void num_sequence<len, beg_pos>::display(ostream &os, const num_sequence &ns, int pos)
{
	os << "The element at posotion "
		<< pos << " for the "
		<< ns.what_am_i() << " sequence is "
		<< ns.elem(pos) << endl;
}

#endif
