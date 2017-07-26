#include "StdAfx.h"
#include "TestUtility.h"

#include <Utility/Utility.h>
#include <Utility/RValueReferences.h>
#include <Utility/MyException.h>
#include <Utility/MyFunction.h>
#include <Utility/MySmartPtr.h>
#include <Utility/MyDateTime.h>

//////////////////////////////////////////////////////////////////////////
/// ����C++11��C���԰汾���ݵ�ͷ�ļ�
#include <cstddef>
#include <cstdlib>
#include <cstring>
/// ����C++11��C���԰汾���ݵ�ͷ�ļ�
//////////////////////////////////////////////////////////////////////////

#pragma comment(lib, "Utility.lib")

CTestUtility::CTestUtility(void)
{
	bool bBaseOf = std::is_base_of<CTestUtility, CTestUtilityChild>::value;
	assert(bBaseOf);
	bBaseOf = std::is_base_of<CTestUtilityChild, CTestUtility>::value;
	assert(!bBaseOf);
}


bool CTestUtility::Test(void)
{
	CMyDateTime::Pointer pMyDateTime = CMyDateTime::Create();
	pMyDateTime->Test();

	CUtility::Pointer pUtility = CUtility::Create();
	pUtility->TestAuto();
	pUtility->TestTuple();

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

void CTestUtility::nullptrTest(void)
{
	CUtility::Pointer pUtility = CUtility::Create();

	/// Call int
	pUtility->Func(1);
	pUtility->Func(0);
	pUtility->Func(NULL);/// ģ���Ĳ���ƥ��
	
	/// Call ptr
	char *psz = "123";
	pUtility->Func(psz);
	pUtility->Func(nullptr);
}

void CTestUtility::TestSmartPtr(void)
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