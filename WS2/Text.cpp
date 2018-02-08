#include "Text.h"

using namespace w3;

Text::Text()
{
	strings = nullptr;
	size_t sizeOfString = 0;
}

/*!In order to allow for the file to be read to a dynamically allocated array of strings, the file is read twice.
The first read through would get the amount of rows that is in the file*/
Text::Text(const string fileName)
{
	ifstream is(fileName);

	if (is.is_open())
	{
		string countline;
		while (!is.fail())
		{
			getline(is, countline, '\n');
			++sizeOfString;
		}
		is.clear();
		is.seekg(0, ios::beg);
		strings = new string[sizeOfString];
		for (int i = 0; !is.fail(); i++)
			getline(is, strings[i], '\n');
		is.close();
	}
	else
		Text();
}


Text::~Text()
{
	delete[] strings;
}

Text::Text(const Text& rhs)
{
	strings = '\0';
	sizeOfString = 0;
	*this = rhs;
}

Text& Text::operator=(const Text& rhs)
{
	if (this != &rhs)
	{
		if (strings != nullptr)
		{
			delete[] strings;
			sizeOfString = 0;
		}
		strings = new string[rhs.sizeOfString];
		for (size_t i = 0; i < rhs.sizeOfString; i++)
			strings[i] = rhs.strings[i];
		sizeOfString = rhs.sizeOfString;
	}
	return *this;
}

Text::Text(Text&& rhs)
{
	strings = '\0';
	sizeOfString = 0;
	*this = move(rhs);
}

Text&& Text::operator=(Text&& rhs)
{
	if (strings != nullptr)
	{
		delete[] strings;
		sizeOfString = 0;
	}
	strings = rhs.strings;
	sizeOfString = rhs.sizeOfString;
	rhs.strings = nullptr;
	rhs.sizeOfString = 0;
	return move(*this);
}



size_t w3::Text::size() const
{
	return sizeOfString;
}