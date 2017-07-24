#include "StdAfx.h"
#include <StudySTL/Container.h>
#include <deque>
#include <array>
#include <list>
#include <forward_list>
#include <set>
#include <unordered_set>
#include <unordered_map>


CContainer::CContainer(void)
{
}


CContainer::~CContainer(void)
{
}

void CContainer::SequenceContainer(void)
{
	TestForwardList();
	TestList();
	TestArray();
	TestDeque();
	TestVector();
}

void CContainer::AssociativeContainer(void)
{
	TestMulteMap();
	TestMultiSet();
}

void CContainer::UnorderedContainer(void)
{
	TestUnorderedMap();
	TestUnorderedMultiSet();
}


void CContainer::AssociativeArray(void)
{
	TestAssociativeArray();
}

void CContainer::Adapter(void)
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
	for(size_t i = 0; i < coll.size(); ++i) {
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
	for(int i = 1; i <= 6; ++i) {
		// insert at the front
		coll.push_front(i * 1.1);
	}

	std::stringstream strStream;
	// print all elements followed by a space
	for(size_t i = 0; i < coll.size(); ++i) {
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
	for(auto& iter = cities.cbegin(); iter != cities.cend(); ++iter) {
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
	for(auto elem = coll.begin(); elem != coll.end(); ++elem) {
		strStream << elem->second << ' ';
	}
	strStream << endl;
	string strOut = strStream.str();
	OutputDebugString(strOut.c_str());
}

void CContainer::TestUnorderedMultiSet(void)
{
	using namespace std;
	unordered_multiset<string> cities;
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
	for(auto &elem = cities.cbegin(); elem != cities.cend(); ++elem)
	{
		strStream << *elem << "  ";;
	}
	strStream << endl;

	// insert additional values:
	cities.insert("London");
	cities.insert("Munich");
	cities.insert("Hanover");
	cities.insert("Braunschweig");

	// print each element:
	for(auto &elem = cities.cbegin(); elem != cities.cend(); ++elem) {
		strStream << *elem << "  ";
	}
	strStream << endl;
	string strOut = strStream.str();
	OutputDebugString(strOut.c_str());
}

void CContainer::TestUnorderedMap(void)
{
	using namespace std;
	unordered_map<string, double> coll;
	coll.insert(std::make_pair("tim", 9.9));
	coll.insert(std::make_pair("struppi", 11.77));

	// square the value of each element:
	for(auto &iter = coll.begin(); iter != coll.end(); ++iter)
	{
		iter->second = iter->second * iter->second;
	}

	stringstream strStream;
	// print each element (key and value):
	for(auto& elem = coll.cbegin(); elem != coll.cend(); ++elem) {
		strStream << elem->first << ": " << elem->second << endl;
	}

	string strOut = strStream.str();
	OutputDebugString(strOut.c_str());
}

void CContainer::TestAssociativeArray(void)
{
	using namespace std;
	// type of the container:
	// - unordered_map: elements are key/value pairs
	// - string: keys have type string
	// - float: values have type float
	unordered_map<string, double> coll;

	// insert some elements into the collection
	// - using the syntax of an associative array
	coll["VAT1"] = 0.16;
	coll["VAT2"] = 0.07;
	coll["Pi"] = 3.1415;
	coll["an arbitrary number"] = 4983.223;
	coll["Null"] = 0;

	coll["cover"] = 1.23;
	coll["cover"] = 2.34;/// OK, ¸²¸ÇÔ­ÓÐÖµ

	// change value
	coll["VAT1"] += 0.03;

	stringstream strStream;
	// print difference of VAT values
	strStream << "VAT difference: " << coll["VAT1"] - coll["VAT2"] << endl;
	string strOut = strStream.str();
	OutputDebugString(strOut.c_str());
}
