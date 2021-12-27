#include <iostream>
#include <vector>

#include "Lifo.h"
#include "stack.h"


using namespace std;

int main()
{
	Lifo li(6);
	
	li.push(4);li.push(5);li.push(2);li.push(6);li.push(1);li.push(8); li.push(41);
	li.print();
	li.pop();li.pop();li.pop();li.pop();
	li.print();

	return 0;
}