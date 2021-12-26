#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <map>
#include <set>
#include <functional>


using namespace std;


int main()
{
	const string one[6] = { "a","an","or","the","and","but" };

	ifstream infile("input_file.txt");

	if (!infile)
	{
		cerr << "unable to open files\n";
		return -1;
	}

	istream_iterator<string> is(infile);
	istream_iterator<string> eof;

	set<string> word_exclusion;
	word_exclusion.insert(one, one + 6);
	map<string, int>words;
	string tmp;

	while (infile >> tmp)
	{
		if (word_exclusion.find(tmp) == word_exclusion.end())
		{
			++words[tmp];
		}
	}

	map<string, int>::iterator it;
	for (it = words.begin(); it != words.end(); ++it)
		cout << it->first << " : " << it->second << endl;

	return 0;
}