#include <iostream>
#include <vector>

using namespace std;

template <typename selemType,typename melemType>
class example
{
public:
	example(selemType min, selemType max) :_min(min), _max(max) {};
	example(melemType *array, int size) :parray(array), _size(size) { _max = *array.max(); _min = *array.min(); };
	selemType& operator[]( int index );
	bool operator==(const melemType&) const;
	bool insert(const melemType*, int);
	selemType min() const{ return _min; };
	selemType max() const{ return _max; };
	int size() const { return _size; };
private:
	int _size;
	melemType *parray;
	selemType _min;
	selemType _max;
};

template <typename selemType, typename melemType>
selemType& example<selemType, melemType>::operator[](int index)
{
	return *parray[index];
}

template <typename selemType, typename melemType>
bool example<selemType,melemType>::operator==(const melemType& arr) const
{
	if (this != arr)
	{
		this->size = arr.size;
		this->parray = &arr;
	}
	return true;
}

template <typename selemType, typename melemType>
bool example<selemType, melemType>::insert(const melemType* arr, int size)
{
	int i = 0;
	while (i < size)
	{
		*parray[parray.size() + 1] = *arr[i];
		i++;
		_size++;
	}
}


int main()
{
	int arr[5] = { 1,2,3,4,5 };
	vector<int>ia(arr, arr + 5);

	example<int, vector<int> > a(&ia,ia.size());

	cout << "size of array is: " << a.size() << endl;
	cout << "min of array is: "<<a.min() << endl;
	cout << "max of array is: " << a.max() << endl;

	return 0;
}