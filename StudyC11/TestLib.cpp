#include "StdAfx.h"
#include "TestLib.h"
#include <TestLib01.h>

#pragma comment(lib, "TestLib.lib")

CTestLib::CTestLib(void)
{
}


CTestLib::~CTestLib(void)
{
}

bool CTestLib::Test(void)
{
	CTestLib01::Pointer pTestLib01 = CTestLib01::Create();

	pTestLib01->TestAuto();

	pTestLib01->TestTuple();

	return true;
}

void CTestLib::nullptrTest(void)
{
	CTestLib01::Pointer pTestLib01 = CTestLib01::Create();

	/// Call int
	pTestLib01->Func(1);
	pTestLib01->Func(0);
	pTestLib01->Func(NULL);/// 模糊的参数匹配
	
	/// Call ptr
	char *psz = "123";
	pTestLib01->Func(psz);
	pTestLib01->Func(nullptr);
}
