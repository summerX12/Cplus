#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <vector>

using namespace std;

class Stack
{
public:
	virtual ~Stack() {};

	virtual bool pop(int &elem) = 0;
	virtual bool push(int elem) = 0;
	virtual int size() const = 0;
	virtual bool empty() const = 0;
	virtual bool full() const = 0;
	virtual int peek() const = 0;
	virtual ostream& print(ostream &os=cout ) const  = 0;

//protected:

};

ostream &operator<<(ostream &os, const Stack &ns)
{
	return ns.print(os);
}

#endif
