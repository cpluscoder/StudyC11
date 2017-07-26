#pragma once

#include <CommonDef.h>

class CTestStlContainer
{
	DEFINE_BOOST_SHARED_PTR(CTestStlContainer)
public:
	
	virtual ~CTestStlContainer(void) {}

	void Test(void);


protected:
	explicit CTestStlContainer(void) {}
};

