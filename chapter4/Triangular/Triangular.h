#ifndef TRIANGULAR_H_
#define TRIANGULAR_H_

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Triangular_iterator {
public:
	Triangular_iterator(int index) :_index(index - 1) {}
	bool operator==(const Triangular_iterator &)const;
	bool operator!=(const Triangular_iterator &)const;
	int operator*() const;
	Triangular_iterator &operator++();
	Triangular_iterator operator++(int);
private:
	void check_integrity() const;
	int _index;
};


class Triangular {
public:
	Triangular(int len = 1, int bp = 1);
	Triangular(const Triangular &);//Memberwise Initialization
	Triangular &operator=(const Triangular &rhs);//copy constructor

	int length() const { return _length; };//get length
	int beg_pos() const { return _beg_pos; };//get beg_pos
	int elem(int pos) const;//get pos value

	void length(int nlen) { _length = nlen; };//set length
	void beg_pos(int npos) { _beg_pos = npos; };//set beg_pos
	
	bool next(int &val) const;//返回下一个元素的值
	void next_reset() const { _next = 1; }//下标重定位到0

	static bool is_elem(int);//判断是否在triangular数列中，如果当前数列最大值没包含，则generate
	static void gen_elements(int length);
	static void gen_elems_to_value(int value);
	static void display(int length, int beg_pos, ostream &os = cout);


	typedef Triangular_iterator iterator;

	Triangular_iterator begin() const
	{
		return Triangular_iterator(_beg_pos);
	}

	Triangular_iterator end() const
	{
		return Triangular_iterator(_beg_pos + _length);
	}

private:
	friend class Triangular_iterator;
	int _length;
	int _beg_pos;
	mutable int _next;
	enum
	{
		 _max_elems = 1024
	};
	static vector<int> _elems;
};


class LessThan
{
public:
	LessThan(int val) :_val(val) {}
	int comp_val() const { return _val; }//获得比较值
	void comp_val(int nval) { _val = nval; }//设置比较值
	bool operator()(int value) const { return value < _val; }
private:
	int _val;
};


#endif
