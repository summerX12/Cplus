#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

bool pent_dispaly(int num);

/*
�Ծֲ���̬��vector����Pentagonal����Ԫ�أ��˺�������һ��constָ�룬ָ���vector
���vector�Ĵ�СС��ָ��Ԫ�ظ�����������
*/

int main()
{
	int pos;
	vector <int> vec;

	cout << "please input a num: " << endl;
	cin >> pos;

	if (pent_dispaly(pos) != 0)
		cerr << "error, the num you enter is too big" << endl;

	return 0;
}

inline bool input_ensure(int num)
{
	if ((num <= 0) || (num > 100))
		return false;
	else
		return true;
}

const vector <int> *static_pentagonal(int num)
{
	static vector <int> vec;
	int i;

	if (num > vec.size())
	{
		for (i = vec.size() + 1; i < num + 1; i++)
			vec.push_back(i * (3 * i - 1) / 2);
	}
	return &vec;
}

bool pent_dispaly(int num)
{
	const vector <int> * vec;
	int i;

	if (input_ensure(num) == false)
		return 1;
	else
	{
		vec = static_pentagonal(num);
		cout << (*vec)[num - 1] << endl;
	}
	for (i = 0; i < (*vec).size(); i++)
		cout << (*vec)[i] << " ";

	return 0;
}