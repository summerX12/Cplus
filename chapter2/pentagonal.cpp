#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void pent_dispaly(vector<int> vec);
bool pentagonal(int num, vector<int> &vec);

/*
用户输入数字num，产生num个Pentagonal数列元素
*/

int main()
{
	int pos;
	vector <int> vec;

	cout << "please input a num: " << endl;
	cin >> pos;

	if (pentagonal(pos, vec) == false)
		cerr << "num is too big" << endl;
	else
	{
		pent_dispaly(vec);
	}
	return 0;
}



bool pentagonal(int num,vector<int> &vec)
{
	int i;

	if ((num <= 0) || (num > 100))
		return false;

	for (i = 1; i <= num; i++)
		vec.push_back(i * (3 * i - 1) / 2);

	return true;
}

void pent_dispaly(vector<int> vec)
{
	int i;

	for (i = 0; i < (vec).size(); i++)
		cout << (vec)[i] << " ";

}