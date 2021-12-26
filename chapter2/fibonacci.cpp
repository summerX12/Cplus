#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void get_fibon_elem();

/*
输入一个数字num，程序返回fibonacci数列的第num项
完成后询问用户是否继续
直至用户选择结束
*/

int main()
{
	get_fibon_elem();

	return 0;
}



int fibon_elem(int pos)
{
	int num, num1 = 1, num2 = 1;

	if ((pos > 1024) || (pos <= 0))
	{
		num = -1;
		//		cout << "the position is not available" << endl;
	}

	if (pos <= 2)
		num = 1;
	else
		num = fibon_elem(pos - 2) + fibon_elem(pos - 1);

	return num;
}

void get_fibon_elem()
{
	int num = 0, pos;
	bool cont = true, next = true;
	char usr_rsp;

	while (next)
	{
		cout << "please input a position in fibonacci: " << endl;
		cin >> pos;

		num = fibon_elem(pos);
		if (num < 0)
			cerr << "the position is not available" << endl;
		else
			cout << "the " << pos << "th number in fibonacci is " << num << endl;

		cont = true;
		while (cont)
		{
			cout << "if you want to calaulate next(y/n) ";
			cin >> usr_rsp;

			if ((usr_rsp == 'n') || (usr_rsp == 'N'))
			{
				next = false;
				cont = false;
			}
			else if ((usr_rsp == 'y') || (usr_rsp == 'Y'))
			{
				cont = false;
			}
			else
				cont = true;
		}
	}
}













