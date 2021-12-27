#include <iostream>
#include <string>
#include <vector>

#include "stack.h"

using namespace std;

class Stack;//ÉùÃ÷

int main()
{
	string str1;
	Stack st1;

	cout << "stack push and pop function test" << endl;
	cout << "Please enter string\n";
	while (cin >> str1 && !st1.full())
	{
		st1.push(str1);
	}

	while (!st1.empty())
	{
		st1.pop(str1);
		cout << str1 << endl;
	}
	cout << endl;

	cout << "stack find and count function test /q1 q2" << endl;
	Stack st;
	int i;
	string my_str[8] = { "this is my stack class test" , "I want to test the function find()", \
		"it is designed for detect if a string is exist" , "each element is a string", \
		"a","b","a","d"};
	
	vector<string>str(my_str,my_str+8);

	string find_str = "b";

	cout << "stack push: \n";
	for (i = 0; i < str.size(); i++)
	{
		st.push(str[i]);
		cout << str[i] << endl;
	}
	cout << endl;

	if (st.find(find_str))
		cout << "find "<<find_str<<endl ;
	else
		cout << "not find " << find_str << endl;;

	i = st.count(find_str);
	cout << "total emerge " << i << " time(s)" << endl;

	cout << endl;
	cout << "stack pop: \n";
	for (i = 0; i < str.size(); i++)
	{
		st.pop(str[i]);
		cout << str[i] << endl;
	}

	return 0;
}