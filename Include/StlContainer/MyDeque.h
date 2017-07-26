#pragma once

#include <CommonDef.h>

class CMyDeque
{
	DEFINE_BOOST_SHARED_PTR(CMyDeque)
public:
	
	virtual ~CMyDeque(void) {}

	void Test(void);

protected:
	explicit CMyDeque(void) {}
};

