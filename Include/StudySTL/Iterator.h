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

	void ErrorUseIter(void);

//////////////////////////////////////////////////////////////////////////
/// 迭代器适配器(iterator adapter)是特殊的迭代器

	/// 插入型迭代器
	/// 调用算法功能时，使用插入(insert)而不是覆盖(overwrite)
	void InsertIter(void);

	///	串流迭代器
	void StreamIter(void);

	/// 反向迭代器
	void ReverseIter(void);

	/// 移动迭代器
	void MoveIter(void);

protected:
	explicit CIterator(void);
};

