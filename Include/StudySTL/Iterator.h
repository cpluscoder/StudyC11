#pragma once

#include <CommonDef.h>

class CIterator
{
	DEFINE_BOOST_SHARED_PTR(CIterator)

public:
	
	virtual ~CIterator(void);

protected:
	explicit CIterator(void);
};

