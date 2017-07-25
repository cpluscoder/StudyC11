#include "StdAfx.h"
#include "StudySTL/Iterator.h"
#include <list>
#include <set>
#include <unordered_set>
#include <deque>
#include <iostream>


using namespace std;

#define DEFAULT_SET_ORDER		1	/// 使用std::set默认排序 1:从小到大(默认) 0:从大到小(定义)


CIterator::CIterator(void)
{
}


CIterator::~CIterator(void)
{
}

void CIterator::Test(void)
{
	// list container for character elements
	list<char> coll;

	// append elements from 'a' to 'z'
	for(char c = 'a'; c <= 'z'; ++c) {
		coll.push_back(c);
	}

	stringstream strOutStream;
	// print all elements: - iterate over all elements
	list<char>::const_iterator pos;
	for(pos = coll.begin(); pos != coll.end(); ++pos) {
		strOutStream << *pos << ' ';
	}
	strOutStream << endl;

	PRINT_STREAM(strOutStream);
}


void CIterator::TestSet(void)
{
	// type of the collection
	typedef std::set<int> IntSet;

	typedef std::set<int, greater<int>> GreaterIntSet;

#if DEFAULT_SET_ORDER
	// set container for int values
	IntSet coll;
#else
	GreaterIntSet coll;
#endif

	// insert elements from 1 to 6 in arbitrary order
	// - note that there are two calls of insert() with value 1
	coll.insert(3);
	coll.insert(1);
	coll.insert(5);
	coll.insert(4);
	coll.insert(1);
	coll.insert(6);
	coll.insert(2);

	stringstream strOutStream;
	// print all elements - iterate over all elements
#if DEFAULT_SET_ORDER
	IntSet::const_iterator pos;
#else
	GreaterIntSet::const_iterator pos;
#endif
	for(pos = coll.begin(); pos != coll.end(); ++pos) {
		strOutStream << *pos << ' ';
	}
	strOutStream << endl;

	PRINT_STREAM(strOutStream);
}

void CIterator::TestUnOrderedSet(void)
{
	// unordered multiset container for int values
	std::unordered_multiset<int> coll;

	// insert some elements
	int nArray[] = {1, 3, 5, 7, 11, 13, 17, 19, 23, 27, 1};
	for(int i = 0; i < COUNT_OF(nArray); ++i)
	{
		coll.insert(nArray[i]);
	}

	stringstream strOutStream;
	// print all elements
	for(auto elem = coll.begin(); elem != coll.end(); ++ elem)
	{
		strOutStream << *elem << ' ';
	}
	strOutStream << std::endl;

	// insert one more element
	coll.insert(25);

	// print all elements again
	for(auto elem = coll.begin(); elem != coll.end(); ++ elem)
	{
		strOutStream << *elem << ' ';
	}
	strOutStream << std::endl;

	PRINT_STREAM(strOutStream);
}

void CIterator::InsertIter(void)
{
	int nArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//list<int> coll1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> coll1;
	for(int i = 0; i < COUNT_OF(nArray); ++i)
	{
		coll1.push_back(nArray[i]);
	}

	/// back_inserter:追加,在容器末端插入(内部调用push_back)
	// copy the elements of coll1 into coll2 by appending them
	vector<int> coll2;
	copy(coll1.cbegin(), coll1.cend(),   // source
		back_inserter(coll2));           // destination

	/// front_inserter:在容器最前端插入(内部调用push_front)
	// copy the elements of coll1 into coll3 by inserting them at the front
	// - reverses the order of the elements
	deque<int> coll3;
	copy(coll1.cbegin(), coll1.cend(),   // source
		front_inserter(coll3));          // destination

	/// inserter:普通插入,(内部调用insert)
	// copy elements of coll1 into coll4
	// - only inserter that works for associative collections
	set<int> coll4;
	copy(coll1.cbegin(), coll1.cend(),   // source
		inserter(coll4, coll4.begin())); // destination
}

void CIterator::StreamIter(void)
{
	vector<string> coll;

	stringstream strInStream;
	for(int i = 0; i < 10; ++i)
	{
		strInStream << i << endl;
	}

	// read all words from the standard input
	// - source: all strings until end-of-file (or error)
	// - destination: coll (inserting)
	copy(istream_iterator<string>(strInStream/*cin*/),   // start of source
		istream_iterator<string>(),       // end of source
		back_inserter(coll));             // destination

	// sort elements
	//sort(coll.begin(), coll.end());
	std::reverse(coll.begin(), coll.end());

	stringstream strOutStream;
	// print all elements without duplicates
	// - source: coll
	// - destination: standard output (with newline between elements)
	unique_copy(coll.cbegin(), coll.cend(),   // source
		ostream_iterator<string>(strOutStream/*cout*/, "\n")); // destination

	PRINT_STREAM(strOutStream);
}

void CIterator::ReverseIter(void)
{
	vector<int> coll;

	// insert elements from 1 to 9
	for (int i = 1; i <= 9; ++i) {
		coll.push_back(i);
	}

	stringstream strOutStream;
	// print all element in reverse order
	copy(coll.crbegin(), coll.crend(),      // source
		ostream_iterator<int>(strOutStream, " "));  // destination
	strOutStream << endl;

	PRINT_STREAM(strOutStream);
}

void CIterator::MoveIter(void)
{
	/// todo...
}

void CIterator::ErrorUseIter(void)
{
	vector<int> coll1;    // empty collection
	vector<int> coll2;    // empty collection

	// RUNTIME ERROR:
	// - beginning is behind the end of the range
	//vector<int>::iterator pos = coll1.begin();
	//reverse(++pos, coll1.end());

	// insert elements from 1 to 9 into coll1
	for(int i = 1; i <= 9; ++i)
	{
		coll1.push_back(i);
	}

	// RUNTIME ERROR:
	// - overwriting nonexisting elements
	//copy(
	//	coll1.cbegin(), coll1.cend(),  // source
	//	coll2.begin());                // destination

	// RUNTIME ERROR:
	// - collections mistaken
	// - cbegin() and cend() refer to different collections
	//copy(
	//	coll1.cbegin(), coll2.cend(),  // source
	//	coll1.end());                  // destination
}
