#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

template <typename elemType>
void display(elemType begin, elemType end)
{
	elemType it;

	for (it = begin; it != end; it++)
	{
		cout << *it << " " ;
	}

}

int main()
{
	int a[8] = { 1,4,6,8,3,7,8,3 };

	list<int> ilist(a,a+8);
	list<int>::iterator it = ilist.begin();
	list<int>::iterator f = find(ilist.begin(), ilist.end(), 8);

	cout << "example list\n";
	cout << "ilist display:" << endl;
	display(ilist.begin(), ilist.end());
	cout << endl;

	cout << "insert 2"<<endl;
	ilist.insert(it,2);
	display(ilist.begin(), ilist.end());
	cout << endl;

	cout << "erase first" << endl;
	ilist.erase(ilist.begin());
	display(ilist.begin(), ilist.end());
	cout << endl;


	cout << "example vector\n";

	vector<int> ivec(a,a+8);
	vector<int>::iterator first = ++ivec.begin();

	cout << "ivec display:" << endl;
	display(ivec.begin(), ivec.end());
	cout << endl;

	cout << "insert 2" << endl;
	ivec.insert(ivec.begin(), 2);
	display(ivec.begin(), ivec.end());
	cout << endl;

	cout << "insert from 8 to last 2" << endl;
	vector<int>::iterator first1 = find(ivec.begin(),ivec.end(),8);
	vector<int>::iterator last = --ivec.end();
	ivec.insert(ivec.begin(), first1,last);
	display(ivec.begin(), ivec.end());
	cout << endl;

	cout << "insert four 2" << endl;
	ivec.insert(ivec.begin(), 4,2);
	display(ivec.begin(), ivec.end());
	cout << endl;

	cout << "erase 8"<<endl;
	first1 = find(ivec.begin(), ivec.end(), 8);
	ivec.erase(first1);
	display(ivec.begin(), ivec.end());
	cout << endl;

	cout << "sort" << endl;
	sort(ivec.begin(), ivec.end(), greater<int>());
	display(ivec.begin(), ivec.end());
	cout << endl;



	return 0;
}