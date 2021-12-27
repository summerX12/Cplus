#include <iostream>
#include <string>

#include "Fibonacci.h"
#include "Pell.h"
#include "Triangular.h"
#include "Lucas.h"
#include "Pentagonal.h"
#include "sequence.h"

using namespace std;

int main()
{
	Fibonacci fib;
	num_sequence::display(cout, fib, 8);

	Pell pe;
	num_sequence::display(cout, pe, 8);

	Triangular tri;
	num_sequence::display(cout, tri, 8);

	return 0;
}