#pragma once

#include <CommonDef.h>

class CCallableObj
{
public:
	explicit CCallableObj(void) {}
	virtual ~CCallableObj(void) {}

	void operator () (int *x, int *y) const
	{
		int nTemp = *x;
		*x = *y;
		*y = nTemp;
	}
};

class CMyFunction
{
	DEFINE_BOOST_SHARED_PTR(CMyFunction)
public:
	
	virtual ~CMyFunction(void);

	void Test(void);

	void SwapNumber1(int *x, int *y) const
	{
		int nTemp = *x;
		*x = *y;
		*y = nTemp;
	}


protected:
	explicit CMyFunction(void);

};

