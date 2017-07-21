#pragma once

#include <CommonDef.h>

class CUtility
{
	DEFINE_BOOST_SHARED_PTR(CUtility)
public:
	
	virtual ~CUtility(void);

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

	void TestTuple(void);

protected:
	explicit CUtility(void);
};

