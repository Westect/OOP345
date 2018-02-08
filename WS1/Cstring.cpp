#include<cstring>
#include<iostream>
#include "Cstring.h"
namespace w1 {

	cstring::cstring(const char * string)
	{
		if (string != NULL)
		{
			strncpy(stringStored, string, MAX);
			stringStored[MAX] = '\0';
		}
		else
			stringStored[0] = '\0';
	}

	void cstring::display(std::ostream & os) const
	{
		os << stringStored;
	}

	std::ostream& operator<<(std::ostream& os, const cstring& string)
	{
		static int insertion = 0;
		os << insertion++ << ": ";
		string.display(os);
		return os;
	}

}
