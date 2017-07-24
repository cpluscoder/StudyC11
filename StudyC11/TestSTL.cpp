#include "StdAfx.h"
#include "TestSTL.h"
#include <StudySTL/Container.h>
#include <StudySTL/Iterator.h>

#pragma comment(lib, "StudySTL.lib")


CTestSTL::CTestSTL(void)
{
}


CTestSTL::~CTestSTL(void)
{
}

void CTestSTL::Test(void)
{
	CIterator::Pointer pIterator = CIterator::Create();
	pIterator->TestUnOrderedSet();
	pIterator->TestSet();
	pIterator->Test();

	CContainer::Pointer pContainer = CContainer::Create();

	pContainer->AssociativeArray();

	pContainer->UnorderedContainer();
	
	pContainer->AssociativeContainer();

	pContainer->SequenceContainer();
}
