#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

class num_sequence
{
public:
	virtual ~num_sequence() {};
	const char* what_am_i() const ;
//	num_sequence(int len, int bp, vector<int> *re=0)
//		: _length(len), _beg_pos(bp), _relems(*re) {};

	int elem(int pos) const;
	ostream& print(ostream &os = cout) const;	
	int length() const { return _length; };
	int beg_pos() const { return _beg_pos; };
	static int max_elems() { return 64; };
	
	static void display(ostream &os, const num_sequence &ns, int pos);

protected:
	virtual void gen_elems(int pos) const = 0 ;//´¿Ðéº¯Êý
	bool check_integrity(int pos,int size) const;

	num_sequence(int len, int bp, vector<int> &re)
		: _length(len), _beg_pos(bp), _relems(re) {};

	int _length;
	int _beg_pos;
	vector<int> & _relems;
};

inline const char* num_sequence::
what_am_i() const
{
	return typeid(*this).name();
}

bool num_sequence::check_integrity(int pos, int size) const
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

int num_sequence::elem(int pos) const
{
	if (!check_integrity(pos, _relems.size()))
		return 0;
	return _relems[pos - 1];
}

ostream& num_sequence::print(ostream &os) const
{
	int ix;
	int end_pos = _beg_pos - 1 + _length;

	if (!check_integrity(end_pos, _relems.size()))
	{
		return os;
	}

	for (ix = _beg_pos - 1; ix < end_pos; ix++)
	{
		os << _relems[ix] << " ";
	}
	os << endl;

	return os;
}

ostream &operator<<(ostream &os, const num_sequence &ns)
{
	return ns.print(os);
}

void num_sequence::display(ostream &os, const num_sequence &ns, int pos)
{
	os << "The element at posotion "
		<< pos << " for the "
		<< ns.what_am_i() << " sequence is "
		<< ns.elem(pos) << endl;
}

#endif
