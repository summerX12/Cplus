#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

/*
q5 实现重载的max()函数，让它接受 两个整数、两个浮点数、两个字符串,一个整数vector、一个浮点型vector、字符串vector、
									一个整数数组。。。。
q6 template 实现q5
*/

void max(int val1, int val2)
{
 	val1 > val2 ? cout << val1 : cout << val2<<endl;
}

void max(double val1, double val2)
{
	val1 > val2 ? cout << val1 : cout << val2 << endl;
}

void max(string val1, string val2)
{
	val1 > val2 ? cout << val1 : cout << val2 << endl;
	cout << endl;
}

void max(const vector<int> vec,int size)
{
	int i,max;

	max = vec[0];
	for (i = 1; i < size; i++)
	{
		if (max < vec[i])
			max = vec[i];
	}
	cout << max << endl;
}

void max(const vector<double> vec, int size)
{
	int i;
	double max;

	max = vec[0];
	for (i = 1; i < size; i++)
	{
		if (max < vec[i])
			max = vec[i];
	}
	cout << max << endl;
}

void max(const vector<string> vec, int size)
{
	int i;
	string max;

	max = vec[0];
	for (i = 1; i < size; i++)
	{
		if (max < vec[i])
			max = vec[i];
	}
	cout << max << endl;
}

void max(const int* arr, int size)
{
	int i, max;

	max = arr[0];
	for (i = 1; i < size; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	cout << max << endl;
}

void max(const double* arr, int size)
{
	int i;
	double max;

	max = arr[0];
	for (i = 1; i < size; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	cout << max << endl;
}



void max(const string* arr, int size)
{
	int i;
	string max;
		
	max = arr[0];
	for (i = 1; i < size; i++)
	{
		if(max < arr[i])
			max = arr[i];
	}
	cout << max << endl;

}




template <typename elemType>
void max_temp(elemType val1 , elemType val2)
{
	val1 > val2 ? cout << val1 : cout << val2 << endl;
}

template <typename elemType>
void max_temp(elemType *arr, int size)
{
	int i;
	elemType max;

	max = arr[0];
	for (i = 1; i < size; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	cout << max << endl;
}

template <typename elemType>
void max_temp(vector<elemType> arr, int size)
{
	int i;
	elemType max;

	max = arr[0];
	for (i = 1; i < size; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	cout << max << endl;
}

int main()
{
	int arr[5] = { 1,2,4,6,7 };
	vector<int> va(arr, arr + 5);

	double arrd[5] = { 1.7,2.5,4.8,6.3,7.9 };
	vector<double> vd(arrd, arrd + 5);

	string arrs[3] = { "hello","c++" ,"world"};
	vector<string> vs(arrs, arrs + 3);

	int len;
	len = sizeof(arrs) / sizeof(*arrs);
	cout << len << endl;


	max(1, 5);
	max(1.3, 5.3);
	max("hello", "c++");
	max(va,5);
	max(vd,5);
	max(vs,3);
	max(arr,5);
	max(arrd,5);
	max(arrs,3);


	cout << endl;
	cout << "template" << endl;
	max_temp(1, 7);
	max_temp(0.2, 5.1);
	max_temp("hello", "c++");
	max_temp(va, 5);
	max_temp(vd, 5);
	max_temp(vs, 3);
	max_temp(arr, 5);
	max_temp(arrd, 5);
	max_temp(arrs, 3);


	return 0;
}