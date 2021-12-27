#include <iostream>
#include <string>
#include <vector>

#include "sequence.h"
#include "Fibonacci.h"


using namespace std;

template <int len, int beg_pos>
void printf(num_sequence<len, beg_pos> *pointer)
{
	pointer->print();
}


void fibonacci(int pos, vector<int> &seq);

int main()
{
	Fibonacci<8> fib1;
	cout << fib1 << endl;
	Fibonacci<8,9> fib2;
	cout << fib2 << endl;

	numeric_sequence<fibonacci> ns_fib(12);
	cout << ns_fib << endl;

  	return 0;
}

void fibonacci(int pos, vector<int> &seq)
{
	if (seq.size() == 0)
	{
		seq.push_back(1);
		seq.push_back(1);
	}
	while(seq.size() < pos)
	{ 
		seq.push_back(seq[seq.size() - 2] + seq[seq.size() - 1]);
	}
}

