#include "StdAfx.h"
#include "StudySTL/Iterator.h"
#include <list>
#include <set>
#include <unordered_set>


#define DEFAULT_SET_ORDER		1	/// 使用std::set默认排序 1:从小到大(默认) 0:从大到小(定义)


CIterator::CIterator(void)
{
}


CIterator::~CIterator(void)
{
}

void CIterator::Test(void)
{
	using namespace std;

	// list container for character elements
	list<char> coll;

	// append elements from 'a' to 'z'
	for(char c = 'a'; c <= 'z'; ++c) {
		coll.push_back(c);
	}

	stringstream strStream;
	// print all elements: - iterate over all elements
	list<char>::const_iterator pos;
	for(pos = coll.begin(); pos != coll.end(); ++pos) {
		strStream << *pos << ' ';
	}
	strStream << endl;

	string strOut = strStream.str();
	OutputDebugString(strOut.c_str());
}


void CIterator::TestSet(void)
{
	using namespace std;

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

	stringstream strStream;
	// print all elements - iterate over all elements
#if DEFAULT_SET_ORDER
	IntSet::const_iterator pos;
#else
	GreaterIntSet::const_iterator pos;
#endif
	for(pos = coll.begin(); pos != coll.end(); ++pos) {
		strStream << *pos << ' ';
	}
	strStream << endl;

	string strOut = strStream.str();
	OutputDebugString(strOut.c_str());
}

void CIterator::TestUnOrderedSet(void)
{
	using namespace std;

	// unordered multiset container for int values
	std::unordered_multiset<int> coll;

	// insert some elements
	int nArray[] = {1, 3, 5, 7, 11, 13, 17, 19, 23, 27, 1};
	for(int i = 0; i < COUNT_OF(nArray); ++i)
	{
		coll.insert(nArray[i]);
	}

	stringstream strStream;
	// print all elements
	for(auto elem = coll.begin(); elem != coll.end(); ++ elem)
	{
		strStream << *elem << ' ';
	}
	strStream << std::endl;

	// insert one more element
	coll.insert(25);

	// print all elements again
	for(auto elem = coll.begin(); elem != coll.end(); ++ elem)
	{
		strStream << *elem << ' ';
	}
	strStream << std::endl;

	string strOut = strStream.str();
	OutputDebugString(strOut.c_str());
}
