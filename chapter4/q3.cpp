#include <iostream>
#include <string>
#include <vector>

using namespace std;

class info {
public:
	static int tests_run() { return _tests_run; }
	static void tests_run(int num) { _tests_run = num; }

	static int tests_pass() { return _tests_pass; }
	static void tests_pass(int num) { _tests_pass = num; }

	static int version_number() { return _version_number; }
	static void version_number(int num) { _version_number = num; }

	static string version_stamp() { return _version_stamp; }
	static void version_stamp(string stamp) { _version_stamp = stamp; }

	static string program_name() { return _program_name; }
	static void program_name(string name) { _program_name = name; }

private:
	static string _program_name;
	static string _version_stamp;
	static int _version_number;
	static int _tests_run;
	static int _tests_pass;
};

int info::_tests_run;
int info::_tests_pass;
int info::_version_number;
string info::_version_stamp;
string info::_program_name;

int main()
{
	info::program_name("chapter4 q3");
	cout << "program_name is: " << info::program_name() << endl;

	info::version_number(1);
	cout <<"version_number is: "<< info::version_number() << endl;

	return 0;
}