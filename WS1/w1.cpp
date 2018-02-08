#include<iostream>
#include "process.h"
using namespace std;

/*!Displays what was inputed in the command line and shows only the first 3 characters, if not enough arguments are inputted into the command line,
displays an error message and exits with error code 1, otherwise exits with error code 0*/
int main(int argc, char* argv[])
{
	cout << "Command line :";
	for (int i = 0; i < argc; i++)
	{
		cout << " " << argv[i];
	}
	cout << "\n";
	if (argc <= 1) {
		cout << "Insufficient number of arguments(min 1)" << endl;
		return 1;
	}
	cout << "Maximum number of characters stored : " << 3 << endl;
	for (int arg = 1; arg < argc; arg++)
		process(argv[arg]);
	return 0;
}