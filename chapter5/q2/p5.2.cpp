#include <iostream>
#include <vector>

#include "Lifo_plus.h"
#include "stack_plus.h"


using namespace std;

int main()
{
	int a;

	Peek li(6);

	li.push(4); li.push(5); li.push(2); li.push(6); li.push(1); li.push(8); 
	li.print();
	li.pop(); li.pop();
	li.print();
	a = li.peek(2);
	cout << a << endl;

	return 0;
}