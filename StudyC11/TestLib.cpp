#include "StdAfx.h"
#include "TestLib.h"

#include <TestLib01.h>
#include <RValueReferences.h>
#include <MyException.h>
#include <MyFunction.h>
#include <MySmartPtr.h>
#include <MyDateTime.h>

//////////////////////////////////////////////////////////////////////////
/// 用于C++11与C语言版本兼容的头文件
#include <cstddef>
#include <cstdlib>
#include <cstring>
/// 用于C++11与C语言版本兼容的头文件
//////////////////////////////////////////////////////////////////////////

#pragma comment(lib, "TestLib.lib")

CTestLib::CTestLib(void)
{
	bool bBaseOf = std::is_base_of<CTestLib, CTestLibChild>::value;
	assert(bBaseOf);
	bBaseOf = std::is_base_of<CTestLibChild, CTestLib>::value;
	assert(!bBaseOf);
}


CTestLib::~CTestLib(void)
{
}

bool CTestLib::Test(void)
{
	CMyDateTime::Pointer pMyDateTime = CMyDateTime::Create();
	pMyDateTime->Test();

	CTestLib01::Pointer pTestLib01 = CTestLib01::Create();
	pTestLib01->TestAuto();
	pTestLib01->TestTuple();

	TestSmartPtr();

	CRValueReferences::Pointer pRValueReferences = CRValueReferences::Create();
	pRValueReferences->Test();

	CMyException::Pointer pMyException = CMyException::Create();
	pMyException->Test();

	CMyFunction::Pointer pMyFunction = CMyFunction::Create();
	pMyFunction->Test();
	pMyFunction->TestFunctional();


	nullptrTest();

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

void CTestLib::TestSmartPtr(void)
{
	CMySmartPtr::Pointer pMySmartPtr = CMySmartPtr::Create();
	pMySmartPtr->CreateSharedPtr();
	pMySmartPtr->DefineDeleteOperator();
	pMySmartPtr->DeleteArrayPtr();
	pMySmartPtr->WeakPtr();
	pMySmartPtr->SharedFromThis();
	pMySmartPtr->TestUniquePtr();
	pMySmartPtr->UniquePtrDeleter();
}