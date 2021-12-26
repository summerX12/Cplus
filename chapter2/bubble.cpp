#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>


using namespace std;

void display(vector <int>vec, ostream &os = cout);
void bubble(vector <int> &vec, ofstream *ofil = 0);

/*
√∞≈›∑®≈≈–Ú
*/
int main()
{
	int ia[8] = { 8,34,3,13,1,21,5,2 };
	vector <int> vec(ia, ia + 8);

	display(vec);
	bubble(vec);
	display(vec);

	return 0;
}


void display(vector <int>vec, ostream &os)
{
	int i;
	for (i = 0; i < vec.size(); i++)
	{
		os << vec[i] << " ";
	}
	os << endl;
}

void bubble(vector <int> &vec, ofstream *ofil)
{
	int i, j, tmp;

	for (i = 0; i < vec.size() - 1; i++)
	{
		for (j = 0; j < vec.size() - 1; j++)
		{
			if (vec[j] > vec[j + 1])
			{
				if (ofil != 0)
					(*ofil) << "swap " << vec[j] << " and " << vec[j + 1] << endl;

				tmp = vec[j + 1];
				vec[j + 1] = vec[j];
				vec[j] = tmp;
			}

		}
	}
}

