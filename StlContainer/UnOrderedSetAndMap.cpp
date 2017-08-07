#include "StdAfx.h"
#include <StlContainer/UnOrderedSetAndMap.h>
#include <unordered_set>
#include <numeric>
#include <iomanip>
#include <unordered_map>


using namespace std;

void CUnOrderedSetAndMap::TestUnOrderedSet(void)
{
	array<int, 10> nArray1 = { 1, 2, 3, 5, 7, 11, 13, 17, 19, 77 };
	// create and initialize unordered set
	unordered_set<int> coll(nArray1.begin(), nArray1.end());

	// print elements
	// - elements are in arbitrary order
	PRINT_ELEMENTS(coll);

	// insert some additional elements
	// - might cause rehashing and create different order
	array<int, 8> nArray2 = {-7, 17, 33, -11, 17, 19, 1, 13};
	coll.insert(nArray2.begin(), nArray2.end());
	PRINT_ELEMENTS(coll);

	// remove element with specific value
	coll.erase(33);

	// insert sum of all existing values
	coll.insert(accumulate(coll.begin(), coll.end(), 0));
	PRINT_ELEMENTS(coll);

	stringstream strOutStream;
	// check if value 19 is in the set
	if(coll.find(19) != coll.end())
	{
		strOutStream << "19 is available" << endl;
	}
	PRINT_STREAM(strOutStream);

	// remove all negative values
	unordered_set<int>::iterator pos;
	for(pos = coll.begin(); pos != coll.end(); )
	{
		if(*pos < 0)
		{
			pos = coll.erase(pos);
		}
		else
		{
			++pos;
		}
	}
	PRINT_ELEMENTS(coll);
}

void CUnOrderedSetAndMap::TestUnOrderedMultiSet(void)
{
	array<int, 10> nArray1 = { 1, 2, 3, 5, 7, 11, 13, 17, 19, 77 };
	// create and initialize, expand, and print unordered multiset
	unordered_multiset<int> coll(nArray1.begin(), nArray1.end());

	array<int, 8> nArray2 = { -7, 17, 33, -11, 17, 19, 1, 13 };
	coll.insert(nArray2.begin(), nArray2.end());

	PRINT_ELEMENTS(coll);

	// remove all elements with specific value
	coll.erase(17);

	// remove one of the elements with specific value
	auto pos = coll.find(13);
	if(pos != coll.end())
	{
		coll.erase(pos);
	}

	PRINT_ELEMENTS(coll);
}


// generic output for pairs (map elements)
template <typename T1, typename T2>
std::ostream& operator << (std::ostream& strm, const std::pair<T1, T2>& p)
{
	return strm << "[" << p.first << "," << p.second << "]";
}

template <typename T>
void printHashTableState(const T& cont)
{
	stringstream strOutStream;
	// basic layout data:
	strOutStream << "size:            " << cont.size() << "\n";
	strOutStream << "buckets:         " << cont.bucket_count() << "\n";
	strOutStream << "load factor:     " << cont.load_factor() << "\n";
	strOutStream << "max load factor: " << cont.max_load_factor() << "\n";
	PRINT_STREAM(strOutStream);

	// iterator category:
	if(typeid(typename std::iterator_traits<typename T::iterator>::iterator_category)
		== typeid(std::bidirectional_iterator_tag))
	{
		strOutStream << "chaining style:  doubly-linked" << "\n";
	}
	else
	{
		strOutStream << "chaining style:  singly-linked" << "\n";
	}
	PRINT_STREAM(strOutStream);

	// elements per bucket:
	strOutStream << "data: " << "\n";
	for(auto idx = 0u; idx != cont.bucket_count(); ++idx)
	{
		strOutStream << " Buckets[" << std::setw(2) << idx << "]: ";
		for(auto pos = cont.begin(idx); pos != cont.end(idx); ++pos)
		{
			strOutStream << *pos << " ";
		}

		strOutStream << "\n";
	}
	strOutStream << std::endl;
	PRINT_STREAM(strOutStream);
}

void CUnOrderedSetAndMap::UnOrdInspect(void)
{
	// create and initialize an unordered set
	array<int, 9> nArray1 = { 1, 2, 3, 5, 7, 11, 13, 17, 19 };
	//std::unordered_set<int> intset = { 1,2,3,5,7,11,13,17,19 };
	std::unordered_set<int> intSet(nArray1.begin(), nArray1.end());
	printHashTableState(intSet);

	// insert some additional values (might cause rehashing)
	array<int, 4> nArray2 = {-7, 17, 33, 4};
	intSet.insert(nArray2.begin(), nArray2.end());
	printHashTableState(intSet);
}


void CUnOrderedSetAndMap::UnOrdMultiMap(void)
{
	// create and initialize an unordered multimap as dictionary
	array<std::pair<string, string>, 6> strArray1 = {
		std::pair<string, string>("day", "Tag"),
		std::pair<string, string>("strange", "fremd"),
		std::pair<string, string>("car", "Auto"),
		std::pair<string, string>("smart", "elegant"),
		std::pair<string, string>("trait", "Merkmal"),
		std::pair<string, string>("strange", "seltsam")
	};
	unordered_multimap<string, string> dict(strArray1.begin(), strArray1.end());
	printHashTableState(dict);

	// insert some additional values (might cause rehashing)
	array<std::pair<string, string>, 3> strArray2 = {
		std::pair<string, string>("smart","raffiniert"),
		std::pair<string, string>("smart","klug"),
		std::pair<string, string>("clever","raffiniert")
	};
	dict.insert(strArray2.begin(), strArray2.end());
	printHashTableState(dict);

	// modify maximum load factor (might cause rehashing)
	dict.max_load_factor(0.7f);
	printHashTableState(dict);
}
