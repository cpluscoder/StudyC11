#pragma once

#include <CommonDef.h>

class CTestLib
{
	DEFINE_BOOST_SHARED_PTR(CTestLib)
public:

	virtual ~CTestLib(void);

	bool Test(void);

	void nullptrTest(void);

	void TestSmartPtr(void);

protected:
	explicit CTestLib(void);
};

class CTestLibChild : public CTestLib
{

};