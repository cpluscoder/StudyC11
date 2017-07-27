#include "StdAfx.h"
#include "TestStlContainer.h"
#include <StlContainer/MyArray.h>
#include <StlContainer/MyVector.h>
#include <StlContainer/MyDeque.h>
#include <StlContainer/MyList.h>
#include <StlContainer/MyForwardList.h>
#include <StlContainer/MySet.h>
#include <StlContainer/MyMap.h>

#pragma comment(lib, "StlContainer.lib")

using namespace std;


void CTestStlContainer::Test(void)
{
	CMyMap::Pointer pMyMap = CMyMap::Create();
	pMyMap->TestRunTimeCmp();
	pMyMap->TestFindIf();
	pMyMap->TestMultiMap();
	pMyMap->TestSubScript();
	pMyMap->TestLambda();

	CMySet::Pointer pMySet = CMySet::Create();
	pMySet->TestRunTimeCompare();
	pMySet->TestMultiSet();
	pMySet->TestSet();
	pMySet->TestSetBound();

	CMyForwardList::Pointer pMyForwardList = CMyForwardList::Create();
	pMyForwardList->TestSplice();
	pMyForwardList->Test();

	CMyList::Pointer pMyList = CMyList::Create();
	pMyList->Test();

	CMyDeque::Pointer pMyDeque = CMyDeque::Create();
	pMyDeque->Test();

	CMyVector::Pointer pMyVector = CMyVector::Create();
	pMyVector->Test();

	CMyArray::Pointer pMyArray = CMyArray::Create();
	pMyArray->TestArray();
	pMyArray->Test();
}

