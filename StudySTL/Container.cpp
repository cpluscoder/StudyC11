#include "StdAfx.h"
#include <StudySTL/Container.h>
#include <deque>
#include <array>
#include <list>
#include <forward_list>
#include <set>


CContainer::CContainer(void)
{
}


CContainer::~CContainer(void)
{
}

void CContainer::TestSequenceContainer(void)
{
	TestForwardList();
	TestList();
	TestArray();
	TestDeque();
	TestVector();
}

void CContainer::TestAssociativeContainer(void)
{
	TestMulteMap();
	TestMultiSet();
}

void CContainer::TestUnorderedContainer(void)
{
	;
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

void CContainer::TestMultiSet(void)
{
	using namespace std;
	multiset<string> cities;
	cities.insert("Braunschweig");
	cities.insert("Hanover");
	cities.insert("Frankfurt");
	cities.insert("New York");
	cities.insert("Chicago");
	cities.insert("Toronto");
	cities.insert("Paris");
	cities.insert("Frankfurt");
	
	stringstream strStream;
	// print each element:
	for(auto elem = cities.cbegin(); elem != cities.cend(); ++elem)
	{
		strStream << *elem << "  ";
	}
	strStream << endl;

	// insert additional values:
	cities.insert("London");
	cities.insert("Munich");
	cities.insert("Hanover");
	cities.insert("Braunschweig");

	// print each element:
	for (auto& iter = cities.cbegin(); iter != cities.cend(); ++iter) {
		strStream << *iter << "  ";
	}
	strStream << endl;

	string strOut;
	strOut = strStream.str();
	OutputDebugString(strOut.c_str());
}

void CContainer::TestMulteMap(void)
{
	using namespace std;
	// container for int/string values
	multimap<int, string> coll;

	// assign some elements in arbitrary order - a value with key 1 gets inserted twice
	std::pair<int, string> pair1(5, "tagged");
	coll.insert(pair1);

	coll.insert(std::make_pair(2, "a"));
	coll.insert(std::make_pair(1,"this"));
	coll.insert(std::make_pair(4, "of"));
	coll.insert(std::make_pair(6, "strings"));
	coll.insert(std::make_pair(1, "is"));
	coll.insert(std::make_pair(3, "multimap"));

	stringstream strStream;
	// print all element values - element member second is the value
	for (auto elem = coll.begin(); elem != coll.end(); ++elem) {
		strStream << elem->second << ' ';
	}
	strStream << endl;
	string strOut = strStream.str();
	OutputDebugString(strOut.c_str());
}
