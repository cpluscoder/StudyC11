#pragma once

#include <CommonDef.h>

class CAlgorithm
{
	DEFINE_BOOST_SHARED_PTR(CAlgorithm);
public:
	
	virtual ~CAlgorithm(void);

	void Test(void);

protected:
	explicit CAlgorithm(void);
};

