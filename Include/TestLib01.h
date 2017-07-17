#pragma once

#include <CommonDef.h>

class CTestLib01
{
	DEFINE_BOOST_SHARED_PTR(CTestLib01)
public:
	
	virtual ~CTestLib01(void);

	bool Test(void);

	/// Test nullptr
	void Func(int nTemp)
	{
		OutputDebugString("Func-int\n");
	}

	void Func(void *pTemp)
	{
		OutputDebugString("Func-ptr\n");
	}

	/// Test auto
	void TestAuto(void);

	
protected:
	explicit CTestLib01(void);
};

