#include "StdAfx.h"
#include <StudySTL/Algorithm.h>


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
