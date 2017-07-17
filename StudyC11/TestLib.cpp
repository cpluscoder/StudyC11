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
	CTestLib01 obj;

	return obj.Test();
}