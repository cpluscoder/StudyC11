#include "StdAfx.h"
#include "TestStlContainer.h"
#include <StlContainer/MyArray.h>
#include <StlContainer/MyVector.h>

#pragma comment(lib, "StlContainer.lib")

using namespace std;


void CTestStlContainer::Test(void)
{
	CMyVector::Pointer pMyVector = CMyVector::Create();
	pMyVector->Test();

	CMyArray::Pointer pMyArray = CMyArray::Create();
	pMyArray->TestArray();
	pMyArray->Test();
}

