#pragma once

#include <CommonDef.h>

class CMyArray
{
	DEFINE_BOOST_SHARED_PTR(CMyArray)
public:
	
	virtual ~CMyArray(void);

	void Test(void);

protected:
	explicit CMyArray(void);
};

