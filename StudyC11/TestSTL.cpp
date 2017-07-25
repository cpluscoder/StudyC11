#include "StdAfx.h"
#include "TestSTL.h"
#include <StudySTL/Container.h>
#include <StudySTL/Iterator.h>
#include <StudySTL/Algorithm.h>

#pragma comment(lib, "StudySTL.lib")


CTestSTL::CTestSTL(void)
{
}


CTestSTL::~CTestSTL(void)
{
}

void CTestSTL::Test(void)
{
	CAlgorithm::Pointer pAlgorithm = CAlgorithm::Create();
	pAlgorithm->TestBind();
	pAlgorithm->TestStlDefaultFuncObj();
	pAlgorithm->TestFunctionObj();
	pAlgorithm->TestForEachNew();
	pAlgorithm->TestLambdaSort();
	pAlgorithm->TestLambda();
	pAlgorithm->TestDoublePredicate();
	pAlgorithm->TestPredicate();
	pAlgorithm->TestTransform();
	pAlgorithm->TestTransformMsdn();
	pAlgorithm->TestForEach();
	pAlgorithm->TestRemove();
	pAlgorithm->TestCopy();
	pAlgorithm->TestFind();
	pAlgorithm->Test();

	CIterator::Pointer pIterator = CIterator::Create();
	pIterator->ReverseIter();
	pIterator->StreamIter();
	pIterator->InsertIter();
	pIterator->TestUnOrderedSet();
	pIterator->TestSet();
	pIterator->Test();

	CContainer::Pointer pContainer = CContainer::Create();
	pContainer->AssociativeArray();
	pContainer->UnorderedContainer();
	pContainer->AssociativeContainer();
	pContainer->SequenceContainer();
}
