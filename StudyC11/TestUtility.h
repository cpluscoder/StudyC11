#pragma once

#include <CommonDef.h>

class CTestUtility
{
	DEFINE_BOOST_SHARED_PTR(CTestUtility)
public:

	virtual ~CTestUtility(void) {}

	bool Test(void);

protected:
	explicit CTestUtility(void);

	void nullptrTest(void);

	void TestSmartPtr(void);
};

class CTestUtilityChild : public CTestUtility {};
