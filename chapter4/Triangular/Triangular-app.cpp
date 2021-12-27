#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

#include "Triangular.h"

using namespace std;

class Triangular_iterator;
class Triangular;
class LessThan;


//重载 iostream 运算符
// cout << 输出Triangular::iterator 类的数据
ostream &operator<<(ostream &os, const Triangular &rhs)
{
	os << "( " << rhs.beg_pos() << "," << rhs.length() << ")";
	rhs.display(rhs.length(), rhs.beg_pos(), os);
	return os;
}

istream &operator>>(istream &is, Triangular &rhs)
{
	char ch1, ch2;
	int bp, len;

	is >> ch1 >> bp >> ch2 >> len;
	rhs.beg_pos(bp);
	rhs.length(len);
	rhs.next_reset();
	return is;
}

int sum(const Triangular &trian)
{
	if (0 == trian.length())
	{
		return 0;
	}
	int val, sum = 0;
	trian.next_reset();
	while ( trian.next(val) )
	{
		sum += val;
	}
	return sum;
}

int count_less_than(const vector<int> &vec,int comp)
{
	int count = 0;
	LessThan lt(comp);

	for (int ix = 0; ix < vec.size(); ix++)
	{
		if (lt(vec[ix]))
		{
			++count;
		}
	}
	return count;
}

void print_less_than(const vector<int> &vec, int comp, ostream &os = cout)
{
	LessThan lt(comp);
	vector<int>::const_iterator iter = vec.begin();
	vector<int>::const_iterator it_end = vec.end();

	os << "elements less than " << lt.comp_val() << endl;
	while ((iter = find_if(iter, it_end, lt)) != it_end)
	{
		os << *iter << " ";
		++iter;
	}
	os << endl;
	return;
}


void prog1()
{
	char ch;
	int ival;
	bool more = true;

	while (more)
	{
		cout << "Enter value: ";
		cin >> ival;

		bool is_elem = Triangular::is_elem(ival);
		cout << ival;
		cout << (is_elem ? " is " : "is not");
		cout << "an element in the Triangular series.\n";
		cout << "Another value?(y/n)";
		cin >> ch;
		if (ch == 'n' || ch == 'N')
		{
			more = false;
		}
	}
	return;
}

void prog2()
{
	Triangular tri(20, 12);
	Triangular::iterator it = tri.begin();
	Triangular::iterator end_it = tri.end();

	cout << "Triangular Series of " << tri.length() << " elememts\n";
	cout << tri << endl;
	while (it != end_it)
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void prog3()
{

	int ia[16] = { 17,44,9,18,45,6,14,23,67,9,0,27,55,8,16 };
	vector<int>vec(ia, ia + 16);
	int comp_val = 20;

	cout << "Number of elements less than ";
	cout << comp_val << " are ";
	cout << count_less_than(vec, comp_val) << endl;
	print_less_than(vec, comp_val);
	return;
}

void prog4()
{
	Triangular tri(6, 3);
	cout << tri << endl;

	Triangular tri2;
	cout << "Please enter as the example (3,5): ";
	cin >> tri2;
	cout << tri2 << endl;
	return;
}

void prog5()
{
	Triangular tri(4,3);
	Triangular::iterator it = tri.begin();
	Triangular::iterator it_end = tri.end();

	cout << "Triangular Series of " << tri.length() << " elements\n";
	cout << tri << endl;

	while (it != it_end)
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	return;
}

int main()
{
	prog5();

	return 0;
}

