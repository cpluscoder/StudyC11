#pragma once

#include <CommonDef.h>

class CTestSTL
{
	DEFINE_BOOST_SHARED_PTR(CTestSTL)
public:
	
	virtual ~CTestSTL(void) {}

	void Test(void);

protected:
	explicit CTestSTL(void) {}
};

