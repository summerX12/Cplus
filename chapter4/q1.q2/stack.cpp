#include <iostream>
#include <string>

#include "stack.h"

using namespace std;

inline bool Stack::empty()
{
	return _stack.empty();
}

bool Stack::pop(string &elem)
{
	if (empty())
		return false;
	elem = _stack.back();
	_stack.pop_back();
	return true;
}

inline bool Stack::full()
{
	return _stack.size() == _stack.max_size();
}

bool Stack::peek(string &elem)
{
	if (empty())
		return false;

	elem = _stack.back();
	return true;
}

bool Stack::push(const string &elem)
{
	if (full())
		return false;

	_stack.push_back(elem);
	return true;
}

bool Stack::find(string &elem)
{
	if (empty())
		return false;

	for (it = _stack.begin(); it != _stack.end(); it++)
	{
		if (*it == elem)
			return true;
	}

	return false;
}

int Stack::count(const string &elem)
{
	int cnt = 0;

	if (empty())
	{
		cnt = 0;
		return cnt;
	}

	for (it = _stack.begin(); it != _stack.end(); it++)
	{
		if (*it == elem)
			cnt++;
	}
	return cnt;
}