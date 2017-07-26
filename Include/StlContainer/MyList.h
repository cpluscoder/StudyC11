#pragma once

#include <CommonDef.h>

class CMyList
{
	DEFINE_BOOST_SHARED_PTR(CMyList)
public:
	
	virtual ~CMyList(void) {}

	void Test(void);

protected:
	explicit CMyList(void) {}
};

