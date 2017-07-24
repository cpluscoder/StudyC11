#include "StdAfx.h"
#include <StudySTL/Algorithm.h>
#include <list>
#include <deque>


CAlgorithm::CAlgorithm(void)
{
}


CAlgorithm::~CAlgorithm(void)
{
}

void CAlgorithm::Test(void)
{
	using namespace std;

	// create vector with elements from 1 to 6 in arbitrary order
	int nArray[] = { 2, 5, 4, 1, 6, 3 };
	vector<int> coll;
	for(int i = 0; i < COUNT_OF(nArray); ++i)
	{
		coll.push_back(nArray[i]);
	}

	stringstream strStream;
	// find and print minimum and maximum elements
	auto minpos = min_element(coll.cbegin(), coll.cend());
	if(minpos != coll.end())
	{
		strStream << "min: "  << *minpos << endl;
	}

	auto maxpos = max_element(coll.cbegin(), coll.cend());
	if(maxpos != coll.end())
	{
		strStream << "max: "  << *maxpos << endl;
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
		strStream << *iter << ' ';
	}
	strStream << endl;

	string strOut = strStream.str();
	OutputDebugString(strOut.c_str());
}

void CAlgorithm::TestFind(void)
{
	using namespace std;
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

	stringstream strStream;
	// print the maximum of the corresponding range
	// - note: including pos25 but excluding pos35
	strStream << "max: " << *max_element(pos25, pos35) << endl;

	// process the elements including the last position
	strStream << "max: " << *max_element(pos25, ++pos35) << endl;

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

	string strOut = strStream.str();
	OutputDebugString(strOut.c_str());
}

void CAlgorithm::TestCopy(void)
{
	using namespace std;
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
