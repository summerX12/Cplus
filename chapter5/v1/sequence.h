#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class num_sequence
{
public:
	static void display(ostream &os, const num_sequence &ns, int pos);
	virtual ~num_sequence() {};
	virtual const char* what_am_i() const = 0;
	virtual int elem(int pos) const = 0;//´¿Ðéº¯Êý
	virtual ostream& print(ostream &os = cout) const = 0;
	static int max_elems();

	virtual int length() = 0;
	virtual int beg_pos() = 0;
protected:
	virtual void gen_elems(int pos) const =0 ;
	virtual bool check_integrity(int pos,int size) const;
	const static int _max_elems = 1024;
};
bool num_sequence::check_integrity(int pos, int size) const
{
	if (pos < 0 || pos > _max_elems)
	{
		cerr << "invalid position\n";
		return false;
	}

	if (pos > size)
		gen_elems(pos);

	return true;
}

int num_sequence::max_elems()
{
	return _max_elems;
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
