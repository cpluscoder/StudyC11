#pragma once

#include <CommonDef.h>

class CFunctionObj
{
public:
	//return-value operator() (arguments) const;
	bool operator() (int x, int y) const
	{
		return x > y;
	}

	void Test(void)
	{
		int nNum1 = 43, nNum2 = 66;
		CFunctionObj obj;
		obj(nNum1, nNum2);
	}
};

class CCallableObj
{
public:
	explicit CCallableObj(void) {}
	virtual ~CCallableObj(void) {}

	void operator () () const
	{
		OutputDebugString("void operator () () const\n");
	}

	void SwapNumber(int *x, int *y) const
	{
		int nTemp = *x;
		*x = *y;
		*y = nTemp;
	}

	/// 这种带参数的调用,编译错误
	void operator () (int *x, int *y) const
	{
		int nTemp = *x;
		*x = *y;
		*y = nTemp;
	}

	template<typename T, typename U>
	auto operator () (T t, U u) const -> decltype(t + u)
	{
		return t + u;
	}
};

class CMyFunction
{
	DEFINE_BOOST_SHARED_PTR(CMyFunction)
public:

	virtual ~CMyFunction(void);

	void Test(void);

	void TestFunctional();

protected:
	explicit CMyFunction(void);
};

