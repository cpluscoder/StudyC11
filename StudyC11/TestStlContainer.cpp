#include "StdAfx.h"
#include "TestStlContainer.h"
#include <StlContainer/MyArray.h>

#pragma comment(lib, "StlContainer.lib")

using namespace std;


void CTestStlContainer::Test(void)
{
	CMyArray::Pointer pMyArray = CMyArray::Create();
	pMyArray->TestArray();
	pMyArray->Test();
}

