#pragma once

#include <CommonDef.h>

/************************************************************************/
/* 算法没有使用面向对象思维（OOP paradigm）                             */
/* 使用的是泛型函数编程思维（generic functional programming paradigm）  */
/* OOP是将数据与操作组织在一起                                          */
/* 使用算法时则被明确划分开来，通过特定的接口实现功能                   */
/* 特别地，某些容器和算法虽然勉强兼容却效率低下                         */
/************************************************************************/
class CAlgorithm
{
	DEFINE_BOOST_SHARED_PTR(CAlgorithm);
public:
	
	virtual ~CAlgorithm(void);

	void Test(void);

	/// 算法中的(容器)区间必须从前到后，使用前必须确定，否则算法行为未知！
	void TestFind(void);

	/// 算法处理多个(容器)区间时,需要程序员确定：目标区间大小 >= 源区间大小
	void TestCopy(void);

	/// 使用迭代器访问容器的算法,不得通过迭代器访问容器自身提供的成员函数
	void TestRemove(void);

	/// 遍历容器
	void TestForEach(void);

	/// 容器复制
	void TestTransform(void);
	void TestTransformMsdn(void);

	/// 判断表达式
	void TestPredicate(void);

	/// 双参数判断表达式
	void TestDoublePredicate(void);

protected:
	void Remove1(void);
	void Remove2(void);
	void Remove3(void);

	/// 算法提供了泛型的容器功能，但对于具体容器，不一定是最优的
	/// 使用std::list最好不要使用算法提供的功能，特别是std::remove
	void Remove4(void);

protected:
	explicit CAlgorithm(void);
};

