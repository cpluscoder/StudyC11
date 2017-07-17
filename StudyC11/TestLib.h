#pragma once

#include <CommonDef.h>

class CTestLib
{
	DEFINE_BOOST_SHARED_PTR(CTestLib)
public:

	virtual ~CTestLib(void);

	bool Test(void);

protected:
	explicit CTestLib(void);
};

