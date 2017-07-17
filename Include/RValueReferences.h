#pragma once

#include <CommonDef.h>

class CRValueReferences
{
	DEFINE_BOOST_SHARED_PTR(CRValueReferences)
public:
	
	virtual ~CRValueReferences(void);

	void Test();

protected:
	explicit CRValueReferences(void);
};

