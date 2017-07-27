#pragma once

#include <CommonDef.h>

class CMyMap
{
	DEFINE_BOOST_SHARED_PTR(CMyMap)
public:
	
	virtual ~CMyMap(void) {}

	void TestLambda(void);

	/// œ¬±Í∑√Œ 
	void TestSubScript(void);

	void TestMultiMap(void);

	void TestFindIf(void);

	void TestRunTimeCmp(void);

protected:
	explicit CMyMap(void) {}
};

