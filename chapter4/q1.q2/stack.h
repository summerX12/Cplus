#ifndef STACK_H_
#define STACK_H_

#include <vector>
#include <string>

using namespace std;

//定义
class Stack {
public:
	//接口
	bool push(const string &);
	bool pop(string &elem);
	bool peek(string &elem);
	bool empty();
	bool full();
	bool find(string &elem);
	int count(const string &);
	int size() { return _stack.size(); }
private:
	//实现
	vector<string> _stack;
	vector<string>::iterator it;
};


#endif
