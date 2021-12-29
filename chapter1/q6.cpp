#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void q_array();


int main()
{
	q_array();

	return 0;
}


void q_array()
{
	int arr_size, i;
	int arr[1024];
	int sum = 0;

	cout << "input a number: ";
	cin >> arr_size;
	cout << "input " << arr_size << " number: ";

	for (i = 0; i < arr_size; ++i)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	cout << "sum of these numbers is " << sum << endl
		<< "average of these numbers is " << sum / arr_size << endl;

	for (i = 0; i < arr_size; ++i)
	{
		cout << arr[i] << endl;
	}
}
