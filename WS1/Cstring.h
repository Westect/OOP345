#include<iostream>
#ifndef W1_CSTRING_H
#define W1_CSTRING_H

namespace w1
{
	const int MAX = 3;
	class cstring {
		char stringStored[MAX + 1];
	public:
		/*!Constructor that takes in an argument of type string, stores the first 3 characters into stringStored*/
		cstring(const char* string);
		/*!Function that takes in an Ostream object as an argument, outputs the stored characters onto the Ostream object*/
		void display(std::ostream& os) const;
	};
	/*!Function that takes in an Ostream object and cstring object, overloads the << operator and allows a cstring object to be outputed with <<, calls for the display function within the cstring class, also displays the number of insertions*/
	std::ostream& operator<<(std::ostream& os, const cstring& foo);
}

#endif
