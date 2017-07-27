#include "StdAfx.h"
#include "TestStlContainer.h"
#include <StlContainer/MyArray.h>
#include <StlContainer/MyVector.h>
#include <StlContainer/MyDeque.h>
#include <StlContainer/MyList.h>
#include <StlContainer/MyForwardList.h>

#pragma comment(lib, "StlContainer.lib")

using namespace std;


void CTestStlContainer::Test(void)
{
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

