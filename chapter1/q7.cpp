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
  ��ȡ�ı��ļ������ݣ����浽vector<string>���󣬱�����vector,��������ʾ��cout,
  ��sort()����
  #include <algorithm>
  sort( container.begin(), container.end() );
  ���������һ���ļ���
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
