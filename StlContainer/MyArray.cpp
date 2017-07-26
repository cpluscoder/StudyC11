#include "StdAfx.h"
#include <StlContainer/MyArray.h>

using namespace std;

CMyArray::CMyArray(void)
{
}


CMyArray::~CMyArray(void)
{
}

void CMyArray::Test(void)
{
	///*const */vector<int> vctTest(4, 2);
	vector<int> vctTest;
	array<int, 10> nArray = { 1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
	CopySrcToDst(nArray, vctTest);

	vector<int>::size_type st = vctTest.size();/// ÈÝÆ÷´óÐ¡
	vector<int>::value_type intValue = 3;
	vctTest.push_back(intValue);

	vector<int>::reference intRef = *(vctTest.begin());
	vector<int>::const_reference intCRef = *(vctTest.begin());

	vector<int>::pointer pInt = &(*vctTest.begin());
	vector<int>::const_pointer cpInt = &(*vctTest.begin());
}
