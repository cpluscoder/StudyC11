#pragma once

#include <CommonDef.h>

class CMySet
{
	DEFINE_BOOST_SHARED_PTR(CMySet)
public:
	
	virtual ~CMySet(void) {}

	void TestSetBound(void);

	void TestSet(void);

	void TestMultiSet(void);

	void TestRunTimeCompare(void);

	void TestRefSharedPtr(void);

protected:
	explicit CMySet(void) {}
};

