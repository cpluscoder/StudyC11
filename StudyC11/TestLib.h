#pragma once

#include <CommonDef.h>

class CTestLib
{
	DEFINE_BOOST_SHARED_PTR(CTestLib)
public:

	virtual ~CTestLib(void);

	bool Test(void);

	void nullptrTest(void);

	void TestRVReferences();

		
protected:
	explicit CTestLib(void);
};

