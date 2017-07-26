#pragma once

#include <CommonDef.h>

class CMyVector
{
	DEFINE_BOOST_SHARED_PTR(CMyVector)
public:
	
	virtual ~CMyVector(void) {}

	void Test(void);

protected:
	explicit CMyVector(void) {}
};

