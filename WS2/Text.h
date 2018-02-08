#ifndef W3_TEXT_H
#define W3_TEXT_H
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

namespace w3
{
	class Text
	{
		string* strings;
		size_t sizeOfString;
	public:
		Text();
		/*!Constructor that takes in an argument of type string, which is the filename being read
		File would be read and and stored in a dynamically allocated array of strings, rows of record is also stored*/
		Text(const string fileName);
		~Text();
		/*!Copy constructor*/
		Text(const Text& rhs);
		/*!Copy constructor operator*/
		Text& operator=(const Text& rhs);
		/*!Move constructor*/
		Text(Text&& rhs);
		/*!Move constructor operator*/
		Text&& operator=(Text&& rhs);
		/*!Move constructor operator*/
		size_t size() const;
	};
}

#endif
