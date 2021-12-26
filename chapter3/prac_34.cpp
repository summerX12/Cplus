#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>


using namespace std;

int main()
{
	ofstream out_odd_file("odd.txt");
	ofstream out_even_file("even.txt");

	if (!out_odd_file || !out_even_file)
	{
		cout << "files open failed!\n";
		return -1;
	}

	istream_iterator<int> is(cin);
	istream_iterator<int> eof;

	vector<int>odd;
	vector<int>even;
	vector<int>tmp;
	vector<int>::iterator it;

//	copy(is, eof, back_inserter(tmp));
	tmp.insert(tmp.begin(), is, eof);

	for (it = tmp.begin(); it != tmp.end(); it++)
	{
		if (*it % 2)
			even.push_back(*it);
		else
			odd.push_back(*it);
	}

	ostream_iterator<int> os_odd(out_odd_file, " ");
	ostream_iterator<int> os_even(out_even_file, " ");

	copy(odd.begin(), odd.end(), os_odd);
	copy(even.begin(), even.end(), os_even);

	return 0;
}