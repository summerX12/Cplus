#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

/*
  ��дһ�������ܹ�ѯ���û�������������ȡ�û���������ݡ�
  ȷ���û���������Ƴ��ȴ��������ַ�������û���������Ч���ƣ�����ӦһЩ��Ϣ��
  �����ַ�ʽʵ�� C-Style / String����
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
