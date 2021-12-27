#include <iostream>
#include <string>

#include "sequence.h"
#include "Fibonacci.h"
#include "Pell.h"

using namespace std;

void printf(num_sequence *pointer)
{
	pointer->print();
}

int main()
{
	Fibonacci fib;
	num_sequence::display(cout, fib, 8);
	cout << "the length of current fibonacci is " << fib.length() << endl;

	Pell pel(6);
	cout << "the length of current pell is "<<pel.length() << endl;
	printf(&pel);
	

	return 0;
}