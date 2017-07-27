#include "StdAfx.h"
#include <set>
#include <StlContainer/MySet.h>

using namespace std;

void CMySet::TestSetBound(void)
{
	set<int> c;

	c.insert(1);
	c.insert(2);
	c.insert(4);
	c.insert(5);
	c.insert(6);

	stringstream strOutStream;

	strOutStream << "lower_bound(3): " << *c.lower_bound(3) << endl;
	strOutStream << "upper_bound(3): " << *c.upper_bound(3) << endl;
	strOutStream << "equal_range(3): " << *c.equal_range(3).first << " " << *c.equal_range(3).second << endl;
	strOutStream << endl;

	strOutStream << "lower_bound(5): " << *c.lower_bound(5) << endl;
	strOutStream << "upper_bound(5): " << *c.upper_bound(5) << endl;
	strOutStream << "equal_range(5): " << *c.equal_range(5).first << " " << *c.equal_range(5).second << endl;

	PRINT_STREAM(strOutStream);
}

void CMySet::TestSet(void)
{
	array<int, 6> nArray = {4, 3, 5, 1, 6, 2};

	// type of the collection:
	// - no duplicates
	// - elements are integral values
	// - descending order

	/// Method 1
	set<int, greater<int>> coll1(nArray.begin(), nArray.end());

	/// Method 2
	//set<int, greater<int>> coll1;
	//coll1.insert(nArray.begin(), nArray.end());

	// insert elements in random order using different member functions
	coll1.insert(5);

	stringstream strOutStream;

	// print all elements
	for(auto iter = coll1.begin(); iter != coll1.end(); ++iter) {
		strOutStream << *iter << ' ';
	}
	strOutStream << endl;
	PRINT_STREAM(strOutStream);

	// insert 4 again and process return value
	auto status = coll1.insert(4);
	if(status.second)
	{
		strOutStream << "4 inserted as element " << distance(coll1.begin(), status.first) + 1 << endl;
	}
	else
	{
		strOutStream << "4 already exists" << endl;
	}
	PRINT_STREAM(strOutStream);

	// assign elements to another set with ascending order
	set<int> coll2(coll1.cbegin(), coll1.cend());
	// print all elements of the copy using stream iterators
	copy(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(strOutStream, " "));
	strOutStream << endl;
	PRINT_STREAM(strOutStream);

	// remove all elements up to element with value 3
	coll2.erase (coll2.begin(), coll2.find(3));
	// remove all elements with value 5
	int num = coll2.erase(5);
	strOutStream << num << " element(s) removed" << endl;
	PRINT_STREAM(strOutStream);

	// print all elements
	copy(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(strOutStream, " "));
	strOutStream << endl;
	PRINT_STREAM(strOutStream);
}

void CMySet::TestMultiSet(void)
{
	// type of the collection:
	// - duplicates allowed
	// - elements are integral values
	// - descending order
	
	array<int, 6> nArray = {4, 3, 5, 1, 6, 2};
	//multiset<int, greater<int>> coll1(nArray.begin(), nArray.end());

	multiset<int, greater<int>> coll1;
	coll1.insert(nArray.begin(), nArray.end());

	// insert elements in random order using different member functions
	coll1.insert(5);

	stringstream strOutStream;
	// print all elements
	copy(coll1.cbegin(), coll1.cend(), ostream_iterator<int>(strOutStream, " "));
	//for(auto iter = coll1.begin(); iter != coll1.end(); ++iter)	{
	//	strOutStream << *iter << ' ';
	//}
	strOutStream << endl;
	PRINT_STREAM(strOutStream);

	// insert 4 again and process return value
	auto ipos = coll1.insert(4);
	strOutStream << "4 inserted as element " << distance(coll1.begin(), ipos) + 1 << endl;
	PRINT_STREAM(strOutStream);

	// assign elements to another multiset with ascending order
	multiset<int> coll2(coll1.cbegin(), coll1.cend());

	// print all elements of the copy using stream iterators
	copy(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(strOutStream, " "));
	strOutStream << endl;
	PRINT_STREAM(strOutStream);

	// remove all elements up to element with value 3
	coll2.erase(coll2.begin(), coll2.find(3));

	// remove all elements with value 5
	int num = coll2.erase (5);
	strOutStream << num << " element(s) removed" << endl;
	PRINT_STREAM(strOutStream);

	// print all elements
	copy(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(strOutStream, " "));
	strOutStream << endl;
	PRINT_STREAM(strOutStream);
}

// type for runtime sorting criterion
class CRunTimeCmp
{
public:
	enum cmp_mode {normal, reverse};

public:  
	// constructor for sorting criterion
	// - default criterion uses value normal
	CRunTimeCmp(cmp_mode m = normal) : _emMode(m) {}

	// comparison of elements
	// - member function for any element type
	template <typename T>
	bool operator() (const T& t1, const T& t2) const
	{
		return _emMode == normal ? t1 < t2 : t2 < t1;
	}

	// comparison of sorting criteria
	bool operator== (const CRunTimeCmp& runTimeCmp) const
	{
		return _emMode == runTimeCmp._emMode;
	}

private:
	cmp_mode _emMode;
};

// type of a set that uses this sorting criterion
typedef set<int, CRunTimeCmp> IntSet;

void CMySet::TestRunTimeCompare(void)
{
	// create, fill, and print set with normal element order
	// - uses default sorting criterion
	array<int, 7> nArray1 = { 4, 7, 5, 1, 6, 2, 5 };
	IntSet coll1(nArray1.begin(), nArray1.end());
	PRINT_ELEMENTS(coll1, "coll1: ");

	// create sorting criterion with reverse element order
	CRunTimeCmp reverse_order(CRunTimeCmp::reverse);

	// create, fill, and print set with reverse element order
	IntSet coll2(reverse_order);
	array<int, 7> nArray2 = { 4, 7, 5, 1, 6, 2, 5 };
	coll2.insert(nArray2.begin(), nArray2.end());
	PRINT_ELEMENTS(coll2, "coll2: ");

	// assign elements AND sorting criterion
	coll1 = coll2;
	coll1.insert(3);
	PRINT_ELEMENTS(coll1, "coll1: ");

	stringstream strOutStream;
	// just to make sure...
	if(coll1.value_comp() == coll2.value_comp())
	{
		strOutStream << "coll1 and coll2 have the same sorting criterion" << endl;
	}
	else
	{
		strOutStream << "coll1 and coll2 have a different sorting criterion" << endl;
	}
	PRINT_STREAM(strOutStream);
}
