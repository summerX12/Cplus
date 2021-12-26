#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>
#include <map>

using namespace std;

const string first_name[6] = {"lippman","smith","mailer","franz","orlen","ranier"};
const vector<string> last_name[6] = { {"ann","jack","emma"},{"tom","emma"},{"lucy","frank"},{"tony"}, {"candy"},{"bob","lily"} };

int main()
{
	map<string, vector<string>>family;
	int i;

	for (i = 0; i < first_name->size()-1; i++)
	{
		family[first_name[i]] = last_name[i];
	}


	map<string, vector<string>>::iterator fa;
	vector<string>::iterator mem;

	for (fa = family.begin(); fa != family.end(); fa++)
	{
		cout << "family : " << fa->first << endl;
		cout << "member : "<<endl;
		for (mem = fa->second.begin(); mem != fa->second.end(); mem++)
		{
			cout << "	 " << *mem << endl;
		}
		cout << endl;
	}


	string name;
	cout << "Who are you want to find?\n";
	cin >> name;
	bool find=false;

	for (fa = family.begin(); fa != family.end(); fa++)
	{
		for (mem = fa->second.begin(); mem != fa->second.end(); mem++)
		{
			if (name == *mem)
			{
				find = true;
				cout << "find " << fa->first << " " << *mem << endl;
			}
		}		
	}
	if (!find)
		cout << "not find " << name;
	cout << endl;

	return 0;
}