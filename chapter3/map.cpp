#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <map>

using namespace std;

int main()
{
	map<string, int> words;
	words["vermeer"] = 1;
	words["am"] = 3;
	//1
	cout << "the first method:" << endl;
	cout << "the count of 'am' is: " << words["am"]<<endl;
	//2
	cout << "the second method:" << endl;
	map<string, int>::iterator it;
	it = words.find("am");
	if (it != words.end())
		cout << "the count of 'am' is: " << it->second << endl;
	else
		cout << "no 'am'\n";
	//3
	cout << "the third method:" << endl;
	if(words.count("am"))
		cout << "the count of 'am' is: " << words["am"] << endl;
	else
		cout << "no 'am'\n";

	cout << endl;
	cout << endl;
	cout << "count the number of words input" << endl;
	cout << "input string" << endl;
	string tword;
	while (cin >> tword)
	{
		words[tword]++;
	}

	map<string, int>::iterator it2 = words.begin();
	for (; it2 != words.end(); ++it2)
		cout << "key: " << it2->first << "  value: " << it2->second << endl;

}