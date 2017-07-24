#include "StdAfx.h"
#include <StudySTL/Algorithm.h>
#include <list>
#include <deque>
#include <set>

using namespace std;

CAlgorithm::CAlgorithm(void)
{
}


CAlgorithm::~CAlgorithm(void)
{
}

void CAlgorithm::Test(void)
{
	// create vector with elements from 1 to 6 in arbitrary order
	int nArray[] = { 2, 5, 4, 1, 6, 3 };
	vector<int> coll;
	for(int i = 0; i < COUNT_OF(nArray); ++i)
	{
		coll.push_back(nArray[i]);
	}

	stringstream strOutStream;
	// find and print minimum and maximum elements
	auto minpos = min_element(coll.cbegin(), coll.cend());
	if(minpos != coll.end())
	{
		strOutStream << "min: "  << *minpos << endl;
	}

	auto maxpos = max_element(coll.cbegin(), coll.cend());
	if(maxpos != coll.end())
	{
		strOutStream << "max: "  << *maxpos << endl;
	}

	// sort all elements
	sort(coll.begin(), coll.end());

	// find the first element with value 3
	// - no cbegin()/cend() because later we modify the elements pos3 refers to
	auto pos3 = find(
		coll.begin(), coll.end(),  // range
		3                          // value
		);
	if(pos3 != coll.end())
	{
		// reverse the order of the found element with value 3 and all following elements
		reverse(pos3, coll.end());
	}

	// print all elements
	for(auto iter = coll.begin(); iter != coll.end(); ++iter)
	{
		strOutStream << *iter << ' ';
	}
	strOutStream << endl;

	string strOut = strOutStream.str();
	OutputDebugString(strOut.c_str());
}

void CAlgorithm::TestFind(void)
{
	list<int> coll;

	// insert elements from 20 to 40
	for(int i = 20; i <= 40; ++i) {
		coll.push_back(i);
	}

	// find position of element with value 3
	// - there is none, so pos3 gets coll.end()
	auto pos3 = find(
		coll.begin(), coll.end(),    // range
		3);                          // value
	if(pos3 != coll.end())
	{
		// reverse the order of elements between found element and the end
		// - because pos3 is coll.end() it reverses an empty range
		reverse(pos3, coll.end());
	}

	// find positions of values 25 and 35
	list<int>::iterator pos25, pos35;
	pos25 = find(
		coll.begin(), coll.end(),  // range
		25);                       // value
	pos35 = find(
		coll.begin(), coll.end(),  // range
		35);                       // value

	stringstream strOutStream;
	// print the maximum of the corresponding range
	// - note: including pos25 but excluding pos35
	strOutStream << "max: " << *max_element(pos25, pos35) << endl;

	// process the elements including the last position
	strOutStream << "max: " << *max_element(pos25, ++pos35) << endl;

	/// 确定 pos25 pos35 的先后顺序
	auto iterPos = find_if(coll.begin(), coll.end(),
	[] (int i)
	{
		return i == 25 || i == 35;
	});
	if(iterPos == coll.end())
	{
		/// 没有 25 35 这两个元素
	}
	else if(*iterPos == 25)
	{
		/// pos25在pos35前
		pos25 = iterPos;
		pos35 = find(++iterPos, coll.end(), 35);
	}
	else
	{
		/// pos35在pos25前
		pos35 = iterPos;
		pos25 = find(++iterPos, coll.end(), 25);
	}

	string strOut = strOutStream.str();
	OutputDebugString(strOut.c_str());
}

void CAlgorithm::TestCopy(void)
{
	//list<int> coll1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int nArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> coll1;
	for(int i = 0; i < COUNT_OF(nArray); ++i)
	{
		coll1.push_back(nArray[i]);
	}

	vector<int> coll2;

	// RUNTIME ERROR:
	// - overwrites nonexisting elements in the destination
	//copy(coll1.cbegin(), coll1.cend(),  // source
	//	coll2.begin());                 // destination

	// resize destination to have enough room for the overwriting algorithm
	coll2.resize(coll1.size());

	// copy elements from first into second collection
	// - overwrites existing elements in destination
	copy(coll1.cbegin(), coll1.cend(),  // source
		coll2.begin());                 // destination

	// create third collection with enough room
	// - initial size is passed as parameter
	deque<int> coll3(coll1.size());

	// copy elements from first into third collection
	copy(coll1.cbegin(), coll1.cend(),  // source
		coll3.begin());                 // destination
}

void CAlgorithm::TestRemove(void)
{
	Remove4();
	Remove3();
	Remove2();
	Remove1();
}

void CAlgorithm::Remove1(void)
{
	list<int> coll;

	// insert elements from 6 to 1 and 1 to 6
	for(int i = 1; i <= 6; ++i) {
		coll.push_front(i);
		coll.push_back(i);
	}

	stringstream strOutStream;
	// print all elements of the collection
	strOutStream << "pre:  ";
	copy(coll.cbegin(), coll.cend(),         // source
		ostream_iterator<int>(strOutStream, " "));   // destination
	strOutStream << endl;

	// remove all elements with value 3
	remove(coll.begin(), coll.end(),      // range
		3);                               // value

	// print all elements of the collection
	strOutStream << "post: ";
	copy(coll.cbegin(), coll.cend(),         // source
		ostream_iterator<int>(strOutStream, " "));   // destination
	strOutStream << endl;

	string strOut = strOutStream.str();
	OutputDebugString(strOut.c_str());
}

void CAlgorithm::Remove2(void)
{
	list<int> coll;

	// insert elements from 6 to 1 and 1 to 6
	for(int i = 1; i <= 6; ++i) {
		coll.push_front(i);
		coll.push_back(i);
	}

	stringstream strOutStream;
	// print all elements of the collection
	copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(strOutStream, " "));
	strOutStream << endl;

	// remove all elements with value 3
	// - retain new end
	list<int>::iterator end = remove(coll.begin(), coll.end(), 3);

	// print resulting elements of the collection
	copy(coll.begin(), end, ostream_iterator<int>(strOutStream, " "));
	strOutStream << endl;

	// print number of removed elements
	strOutStream << "number of removed elements: " << distance(end, coll.end()) << endl;

	// remove "removed" elements
	coll.erase(end, coll.end());

	// print all elements of the modified collection
	copy(coll.cbegin(), coll.cend(),
		ostream_iterator<int>(strOutStream, " "));
	strOutStream << endl;

	string strOut = strOutStream.str();
	OutputDebugString(strOut.c_str());
}

void CAlgorithm::Remove3(void)
{
	stringstream strOutStream;
	
	// unordered set with elements from 1 to 9
	//set<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int nArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	set<int> coll;
	for(int i = 0; i < COUNT_OF(nArray); ++i)
	{
		coll.insert(nArray[i]);
	}

	// print all elements of the collection
	copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(strOutStream, " "));
	strOutStream << endl;

	// Remove all elements with value 3
	// - algorithm remove() does not work
	// - instead member function erase() works
	int num = coll.erase(3);

	// print number of removed elements
	strOutStream << "number of removed elements: " << num << endl;

	// print all elements of the modified collection
	copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(strOutStream, " "));
	strOutStream << endl;

	string strOut = strOutStream.str();
	OutputDebugString(strOut.c_str());
}

void CAlgorithm::Remove4(void)
{
	list<int> coll;

	// insert elements from 6 to 1 and 1 to 6
	for(int i = 1; i <= 6; ++i) {
		coll.push_front(i);
		coll.push_back(i);
	}
	PRINT_ELEMENTS(coll);

	// remove all elements with value 3 (poor performance)
	auto iterEnd = remove(coll.begin(), coll.end(), 3);
	if(iterEnd != coll.end())
	{
		coll.erase(iterEnd, coll.end());
		PRINT_ELEMENTS(coll);
	}

	// remove all elements with value 4 (good performance)
	coll.remove(4);
	PRINT_ELEMENTS(coll);
}
