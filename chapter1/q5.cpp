#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

/*
  编写一个程序，能够询问用户的姓名，并读取用户输入的内容。
  确保用户输入的名称长度大于两个字符。如果用户输入了有效名称，就响应一些信息，
  以两种方式实现 C-Style / String对象
 */

void q_cstyle();
void q_string();


int main()
{
	q_cstyle();
	q_string();

	return 0;
}

void q_cstyle()
{
	char str[1024];
	int len;

	cout << "What's your name: ";
	cin >> str;
	//cout << "the length of input is: " << strlen(str) << endl;
	len = strlen(str);

	switch (len)
	{
	case 0:
		cout << "your name is empty!" << endl;
		break;
	case 1:
		cout << "your name is too short! " << endl;
		break;
	default:
		cout << "hello " << str << endl;
		break;
	}

}

void q_string()
{
	string str;
	int len;

	cout << "input a string: ";
	cin >> str;
	//	cout << "the length of input is: " << str.size() <<endl;
	len = str.size();

	switch (len)
	{
	case 0:
		cout << "your name is empty!" << endl;
		break;
	case 1:
		cout << "your name is too short! " << endl;
		break;
	default:
		cout << "hello " << str << endl;
		break;
	}
}
