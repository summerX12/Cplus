#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void file();

int main()
{
	file();

	return 0;
}

/*
  读取文本文件中内容，保存到vector<string>对象，遍历该vector,将内容显示到cout,
  用sort()排序
  #include <algorithm>
  sort( container.begin(), container.end() );
  并输出到另一个文件中
*/

void file()
{
	vector <int> vt;
	int i, temp;

	ifstream infile("17.txt");
	ofstream outfile("17.1.txt");

	if (!infile && !outfile)
		cout << "file operation failed" << endl;
	else
	{
		while (infile >> temp)
		{
			vt.push_back(temp);
		}
	}

	sort(vt.begin(), vt.end());
	cout << "sorted number" << endl;
	for (i = 0; i < vt.size(); ++i)
	{
		cout << vt[i] << endl;
		outfile << vt[i] << endl;
	}

}
