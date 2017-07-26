#include "StdAfx.h"
#include <StlContainer/MyVector.h>


using namespace std;

void CMyVector::Test(void)
{
	// create empty vector for strings
	vector<string> sentence;

	// reserve memory for five elements to avoid reallocation
	sentence.reserve(5);

	array<string, 4> strArray = {"how","are","you","?"};
	vector<string> vctTemp;
	CopySrcToDst(strArray, vctTemp);

	// append some elements
	sentence.push_back("Hello,");
	sentence.insert(sentence.end(), vctTemp.begin(), vctTemp.end());

	stringstream strOutStream;
	// print elements separated with spaces
	copy(sentence.cbegin(), sentence.cend(), ostream_iterator<string>(strOutStream, " "));
	strOutStream << endl;
	// print "technical data"
	strOutStream << "  max_size(): " << sentence.max_size() << endl;
	strOutStream << "  size():     " << sentence.size()     << endl;
	strOutStream << "  capacity(): " << sentence.capacity() << endl;
	PRINT_STREAM(strOutStream);

	// swap second and fourth element
	swap(sentence[1], sentence[3]);
	// insert element "always" before element "?"
	sentence.insert(find(sentence.begin(), sentence.end(),"?"), "always");
	// assign "!" to the last element
	sentence.back() = "!";
	// print elements separated with spaces
	copy(sentence.cbegin(), sentence.cend(), ostream_iterator<string>(strOutStream, " "));
	strOutStream << endl;
	// print some "technical data" again
	strOutStream << "  size():     " << sentence.size()     << endl;
	strOutStream << "  capacity(): " << sentence.capacity() << endl;
	PRINT_STREAM(strOutStream);

	// delete last two elements
	sentence.pop_back();
	sentence.pop_back();
	// shrink capacity (since C++11)
	sentence.shrink_to_fit();
	copy(sentence.cbegin(), sentence.cend(), ostream_iterator<string>(strOutStream, " "));
	strOutStream << endl;
	// print some "technical data" again
	strOutStream << "  size():     " << sentence.size()     << endl;
	strOutStream << "  capacity(): " << sentence.capacity() << endl;
	PRINT_STREAM(strOutStream);
}
