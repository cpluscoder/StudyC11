#include "StdAfx.h"
#include <Utility/MyFunction.h>
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
	int x = 11, y = 22, nResult = 0;
	
	auto bindFunc1 = std::bind(::SwapNumber, &x, &y);
	bindFunc1(&x, &y);
	nResult = x;
	nResult = y;
	
	CCallableObj obj;
	std::shared_ptr<CCallableObj> spCallableObj(new CCallableObj);

	// bind() uses callable objects to bind arguments
	auto bindFunc2 = std::bind(CCallableObj());
	bindFunc2();

	auto bindFunc3 = std::bind(&CCallableObj::SwapNumber, obj, std::placeholders::_1, std::placeholders::_2);
	bindFunc3(&x, &y);
	nResult = x;
	nResult = y;

	auto bindFunc4 = std::bind(&CCallableObj::SwapNumber, spCallableObj, std::placeholders::_1, std::placeholders::_2);
	bindFunc4(&x, &y);
	nResult = x;
	nResult = y;

	auto lambdaFunc = [] (int *x, int *y)
	{
		int nTemp = *x;
		*x = *y;
		*y = nTemp;
	};
	//auto bindFunc5 = std::bind(lambdaFunc, std::placeholders::_1, std::placeholders::_2);
	//bindFunc5(&x, &y);
}

void CMyFunction::TestFunctional()
{
	std::vector<std::function<void(int *, int *)>> tasks;
	tasks.push_back(::SwapNumber);
	tasks.push_back([] (int *x, int *y) {
		*x = *x * 2;
		*y = *y * 2;
	});
	auto lambdaFunc = [] (int *x, int *y) {
		::SwapNumber(x, y);
	};
	tasks.push_back(lambdaFunc);

	int nNum1 = 23;
	int nNum2 = 54;
	int nResult = 0;
	for(auto iter = tasks.begin(); iter != tasks.end(); ++iter)
	{
		(*iter)(&nNum1, &nNum2);
		nResult = nNum1;
		nResult = nNum2;
	}

	std::function<void (const CCallableObj&, int *, int *)> funcMember;
	funcMember = &CCallableObj::SwapNumber;
	CCallableObj obj;
	funcMember(obj, &nNum1, &nNum2);
	nResult = nNum1;
	nResult = nNum2;
}
