#pragma once

#include <CommonDef.h>

class CIterator
{
	DEFINE_BOOST_SHARED_PTR(CIterator)

public:
	
	virtual ~CIterator(void);

	///	iterator:       以 "读/写" 模式遍历容器
	/// const_iterator: 以 "只读"  模式遍历容器
	/// ++iter 比 iter++ 效率高 (iter++ 需要临时对象)
	void Test(void);

	/// 操作后容器中的元素保持顺序
	void TestSet(void);

	/// 操作后容器中的元素顺序不确定
	void TestUnOrderedSet(void);

protected:
	explicit CIterator(void);
};

