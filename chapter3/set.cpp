#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main()
{
	int a[10] = { 1,2,6,8,3,3,2,5,6,8 };
	vector<int>vec(a, a + 10);
	set<int>iset(vec.begin(), vec.end());
	set<int>::iterator it;

	cout << "display set" << endl;
	for (it = iset.begin(); it != iset.end(); ++it)
		cout << *it << " ";
	cout << endl;

	cout << "insert 0" << endl;
	iset.insert(0);
	for (it = iset.begin(); it != iset.end(); ++it)
		cout << *it << " ";
	cout << endl;

	cout << "insert from set begin to end" << endl;
	iset.insert(vec.begin(), vec.end());
	for (it = iset.begin(); it != iset.end(); ++it)
		cout << *it << " ";
	cout << endl;


	cout << endl;
	cout << "exclusion text:" << endl
		<<"enter string;"<<endl;

	const string ex_arr[6] = { "a","an","or","the","and","but" };
	set<string> word_exclusion;
	word_exclusion.insert(ex_arr, ex_arr + 6);
	map<string,int>words;
	map<string, int>::iterator itm;
	string tword;

	while (cin >> tword)
	{
		if (word_exclusion.count(tword))
			continue;
		words[tword]++;
	}
	for (itm = words.begin(); itm != words.end(); ++itm)
		cout << itm->first << " : " << itm->second << endl;


}
