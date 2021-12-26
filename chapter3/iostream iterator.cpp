#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	//从终端输入 排序后输出到终端
	cout << "input from terminal and sort, then display" << endl;
	istream_iterator<string> is (cin);
	istream_iterator<string> eof;

	vector<string> text;
	copy(is, eof, back_inserter(text));

	sort(text.begin(), text.end());

	ostream_iterator<string> os(cout, " ");
	copy(text.begin(), text.end(), os);
	cout << endl << endl;

	//从文件读取 排序后写到文件
	cout << "input from input_file.txt and sort, then output to outfile.txt" << endl;
	ifstream in_file("input_file.txt");
	ofstream out_file("output_file.txt");

	if (!in_file || !out_file)
	{
		cerr << "unable to open files\n";
		return -1;
	}

	istream_iterator<string> isf(in_file);
	istream_iterator<string> eoff;

	vector<string> textf;
	copy(isf, eoff, back_inserter(textf));

	sort(textf.begin(), textf.end());

	ostream_iterator<string> osf(out_file, " ");
	copy(textf.begin(), textf.end(), osf);
	cout << "finish" << endl;

	return 0;
}