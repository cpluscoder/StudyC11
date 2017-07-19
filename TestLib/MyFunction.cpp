#include "StdAfx.h"
#include "MyFunction.h"
#include <functional>

using namespace std;

void SwapNumber(int *x, int *y)
{
	int nTemp = *x;
	*x = *y;
	*y = nTemp;
}


CMyFunction::CMyFunction(void)
{
}


CMyFunction::~CMyFunction(void)
{
}

void CMyFunction::Test(void)
{
	auto lambdaRtn = [&] (int *x, int *y)
	{
		int nTemp = *x;
		*x = *y;
		*y = nTemp;
	};
	CCallableObj obj;
	std::shared_ptr<CCallableObj> spCallableObj(new CCallableObj);

	int x = 11, y = 22;
	// bind() uses callable objects to bind arguments
	std::bind(::SwapNumber, &x, &y)();/// SwapNumber(11, 22)
	//std::bind(lambdaRtn, x, y)();/// lambda(23, 34)
	//std::bind(CCallableObj(), x, y)();
	//std::bind(&CMyFunction::SwapNumber1, obj, x, y)();
	//std::bind(&CMyFunction::SwapNumber1, spCallableObj, x, y)();
}
