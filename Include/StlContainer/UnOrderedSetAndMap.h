#pragma once

#include <CommonDef.h>

class CUnOrderedSetAndMap
{
	DEFINE_BOOST_SHARED_PTR(CUnOrderedSetAndMap)
public:
	
	void TestUnOrderedSet(void);

	void TestUnOrderedMultiSet(void);

	void UnOrdInspect(void);

	void UnOrdMultiMap(void);

	virtual ~CUnOrderedSetAndMap(void) {}

protected:
	explicit CUnOrderedSetAndMap(void) {}
};

