#include "StdAfx.h"
#include <StudySTL/Container.h>
#include <deque>
#include <array>
#include <list>
#include <forward_list>


CContainer::CContainer(void)
{
}


CContainer::~CContainer(void)
{
}

void CContainer::Test(void)
{
	TestForwardList();
	TestList();
	TestArray();
	TestDeque();
	TestVector();
}

void CContainer::TestVector(void)
{
	// vector container for integer elements
	std::vector<int> coll;

	// append elements with values 1 to 6
	for(int i = 1; i <= 6; ++i) {
		coll.push_back(i);
	}

	std::stringstream strStream;
	// print all elements followed by a space
	for (size_t i = 0; i < coll.size(); ++i) {
		strStream << coll[i] << ' ';
	}
	strStream << std::endl;

	std::string strOut;
	strOut = strStream.str();
	OutputDebugString(strOut.c_str());
}

void CContainer::TestDeque(void)
{
	// deque container for floating-point elements
	std::deque<double> coll;

	// insert elements from 1.1 to 6.6 each at the front
	for (int i = 1; i <= 6; ++i) {
		// insert at the front
		coll.push_front(i * 1.1);
	}

	std::stringstream strStream;
	// print all elements followed by a space
	for (size_t i = 0; i < coll.size(); ++i) {
		strStream << coll[i] << ' ';
	}
	strStream << std::endl;

	std::string strOut;
	strOut = strStream.str();
	OutputDebugString(strOut.c_str());
}

void CContainer::TestArray(void)
{
	// array container of 5 string elements:
	std::array<std::string, 5> coll = { "hello", "world" };

	std::stringstream strStream;
	// print each element with its index on a line
	for(size_t i = 0; i < coll.size(); ++i) {
		strStream << i << ": " << coll[i] << std::endl;
	}

	std::string strOut;
	strOut = strStream.str();
	OutputDebugString(strOut.c_str());
}

void CContainer::TestList(void)
{
	// list container for character elements
	std::list<char> coll;

	// append elements from 'a' to 'z'
	for(char c = 'a'; c <= 'z'; ++c) {
		coll.push_back(c);
	}

	std::stringstream strStream;
	// print all elements: - use range-based for loop
	for(auto iter = coll.begin(); iter != coll.end(); ++iter) {
		strStream << *iter << ' ';
	}
	strStream << std::endl;

	std::string strOut;
	strOut = strStream.str();
	OutputDebugString(strOut.c_str());
}

void CContainer::TestForwardList(void)
{
	// create forward-list container for some prime numbers
	std::forward_list<long> coll;
	std::array<long, 7> arrSrc = {2, 3, 5, 7, 11, 13, 17};
	for(auto iter = arrSrc.rbegin(); iter != arrSrc.rend(); ++iter) {
		coll.push_front(*iter);
	}

	// resize two times - note: poor performance
	coll.resize(9);
	coll.resize(10, 99);

	std::stringstream strStream;
	// print all elements:
	for(auto iter = coll.begin(); iter != coll.end(); ++iter) {
		strStream << *iter << ' ';
	}
	strStream << std::endl;

	std::string strOut;
	strOut = strStream.str();
	OutputDebugString(strOut.c_str());
}