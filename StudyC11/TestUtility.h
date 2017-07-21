#pragma once

#include <CommonDef.h>

class CTestUtility
{
	DEFINE_BOOST_SHARED_PTR(CTestUtility)
public:

	virtual ~CTestUtility(void);

	bool Test(void);

	void nullptrTest(void);

	void TestSmartPtr(void);

protected:
	explicit CTestUtility(void);
};

class CTestUtilityChild : public CTestUtility
{

};