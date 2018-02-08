#include "process.h"
#include "Cstring.h"
#include <iostream>

using namespace std;

/*Function that takes in a string, outputs a cstring object and inserts a new line afterwards*/
void process(const char * string)
{
	w1::cstring foo(string);
	cout << foo;
	cout << "\n";
}
