#include "StdAfx.h"
#include <deque>
#include <StlContainer/MyDeque.h>


using namespace std;

void CMyDeque::Test(void)
{
	// create empty deque of strings
	deque<string> coll;

	// insert several elements
	coll.assign(3, string("string"));
	coll.push_back("last string");
	coll.push_front("first string");

	stringstream strOutStream;
	// print elements separated by newlines
	copy(coll.cbegin(), coll.cend(), ostream_iterator<string>(strOutStream, "\n"));
	strOutStream << endl;
	PRINT_STREAM(strOutStream);

	// remove first and last element
	coll.pop_front();
	coll.pop_back();

	// insert "another" into every element but the first
	for(unsigned i = 1; i < coll.size(); ++i) {
		coll[i] = "another " + coll[i];
	}

	// change size to four elements
	coll.resize(4, "resized string");

	// print elements separated by newlines
	copy(coll.cbegin(), coll.cend(), ostream_iterator<string>(strOutStream, "\n"));
	PRINT_STREAM(strOutStream);
}
