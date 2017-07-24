#include "StdAfx.h"
#include "TestSTL.h"
#include <StudySTL/Container.h>

#pragma comment(lib, "StudySTL.lib")


CTestSTL::CTestSTL(void)
{
}


CTestSTL::~CTestSTL(void)
{
}

void CTestSTL::Test(void)
{
	CContainer::Pointer pContainer = CContainer::Create();

	pContainer->TestUnorderedContainer();
	
	pContainer->TestAssociativeContainer();

	pContainer->TestSequenceContainer();
}
