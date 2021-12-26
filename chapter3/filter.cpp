#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <functional>
#include <iterator>

using namespace std;

template <typename InputIterator, typename OutputInterator, typename ElemType, typename Comp>

OutputInterator filter(InputIterator first, InputIterator last, OutputInterator at, const ElemType &val, Comp pred)
{
	while ((first = find_if(first, last, bind2nd(pred, val))) != last)
	{
		cout << "find value: " << *first << endl;
		*at++ = *first++;
	}
	return at;
}

int main()
{
	int a[8] = { 12,8,43,0,6,21,3,7 };
	vector<int>ivec(a, a + 8);

	int b[8];
	vector<int>ivec1(8);

	cout << "filter value less than 8\n";
	filter(a, a + 8, b, 8, less<int>());

	cout << "filter value greater than 8\n";
	filter(ivec.begin(), ivec.end(), ivec1.begin(), 8, greater<int>());

	cout << "filter value greater than 8\n";
	vector<int>ivec2;
	filter(ivec.begin(), ivec.end(), back_inserter(ivec2), 8, greater<int>());
}