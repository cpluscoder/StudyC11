#pragma once

#include <CommonDef.h>

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

	/// �������ı������
	void operator () (int *x, int *y) const
	{
		int nTemp = *x;
		*x = *y;
		*y = nTemp;
	}

	/// ������
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

