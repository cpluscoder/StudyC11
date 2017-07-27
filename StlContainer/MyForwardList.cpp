#include "StdAfx.h"
#include <forward_list>
#include <StlContainer/MyForwardList.h>

using namespace std;

void CMyForwardList::Test(void)
{
	array<int, 8> nArray = { 1, 2, 3, 4, 5, 97, 98, 99 };
	forward_list<int> listTest;
	for(auto iter = nArray.rbegin(); iter != nArray.rend(); ++iter)
	{
		listTest.push_front(*iter);
	}

	// find the position before the first even element
	auto posBefore = listTest.before_begin();
	for(auto pos = listTest.begin(); pos != listTest.end(); ++pos, ++posBefore)
	{
		if(*pos % 2 == 0)
		{
			break;  // element found
		}
	}

	// and insert a new element in front of the first even element
	listTest.insert_after(posBefore, 42);
	PRINT_ELEMENTS(listTest);
}

void printLists(const string& s, const forward_list<int>& l1, const forward_list<int>& l2)
{
	stringstream strOutStream;
	strOutStream << s << endl;
	strOutStream << " list1: ";
	copy (l1.cbegin(), l1.cend(), ostream_iterator<int>(strOutStream, " "));
	strOutStream << endl << " list2: ";
	copy (l2.cbegin(), l2.cend(), ostream_iterator<int>(strOutStream, " "));
	strOutStream << endl;
	PRINT_STREAM(strOutStream);
}


void CMyForwardList::TestSplice(void)
{
	array<int, 5> nArray1 = { 1, 2, 3, 4, 5 };
	array<int, 3> nArray2 = { 97, 98, 99 };
	forward_list<int> list1, list2;
	for(auto iter = nArray1.rbegin(); iter != nArray1.rend(); ++iter)
	{
		list1.push_front(*iter);
	}
	for(auto iter = nArray2.rbegin(); iter != nArray2.rend(); ++iter)
	{
		list2.push_front(*iter);
	}
	printLists ("initial:", list1, list2);

	// insert six new element at the beginning of list2
	list2.insert_after(list2.before_begin(), 99);
	list2.push_front(10);

	array<int, 4> nArray3 = {10, 11, 12, 13};
	forward_list<int> list3;
	for(auto iter = nArray3.rbegin(); iter != nArray3.rend(); ++iter)
	{
		list3.push_front(*iter);
	}
	list2.insert_after(list2.before_begin(), list3.begin(), list3.end());
	printLists("6 new elems:", list1, list2);

	// insert all elements of list2 at the beginning of list1
	list1.insert_after(list1.before_begin(), list2.begin(), list2.end());
	printLists("list2 into list1:", list1, list2);

	// delete second element and elements after element with value 99
	list2.erase_after(list2.begin());
	list2.erase_after(
		find(list2.begin(),list2.end(), 99),
		list2.end());
	printLists("delete 2nd and after 99:", list1, list2);

	// sort list1, assign it to list2, and remove duplicates
	list1.sort();
	list2 = list1;
	list2.unique();
	printLists("sorted and unique:", list1, list2);

	// merge both sorted lists into list1
	list1.merge(list2);
	printLists("merged:", list1, list2);

/*
	// find 3 in l1
	auto pos1 = l1.before_begin();
	for(auto pb1 = l1.begin(); pb1 != l1.end(); ++pb1, ++pos1) {
		if(*pb1 == 3) {
			break;  // found
		}
	}

	// find 99 in l2
	auto pos2 = l2.before_begin();
	for(auto pb2 = l2.begin(); pb2 != l2.end(); ++pb2, ++pos2) {
		if(*pb2 == 99) {
			break;  // found
		}
	}

	// splice 3 from l1 to l2 before 99
	//l1.splice_after(
	//	pos2, l2,  // destination
	//	pos1);     // source

	PRINT_ELEMENTS(l1, "l1: ");
	PRINT_ELEMENTS(l2, "l2: ");
*/
}
