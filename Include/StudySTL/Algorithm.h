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

	///	C++编译器对Lambda优化 高于 普通函数
	///	Lambda为使用STL算法功能提供了最高级的方便、快速、可读、可维护
	/// 相比函数对象:Lambda内部无状态(成员变量)，其运行参数由调用者定义，并通过 [&] [=] 传递参数
	void TestLambda(void);

	///	序列容器(Vector, Deque, Array, List, ForwardList)使用STL算法功能时，使用Lambda较优雅
	/// 否则：需要在容器定义指定Lambda, 并且需要decltype产生类型，在构造容器时显示确定Lambda对象
	void TestLambdaSort(void);

	void TestForEachNew(void);

	void TestFunctionObj(void);

	void TestStlDefaultFuncObj(void);

	void TestBind(void);

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

/*! @brief	函数对象使用说明
 * 1 函数对象是一种带状态的函数
 *   函数对象可拥有成员变量和成员函数
 * 2 函数对象有各自的类型
 *   对于template泛型编程更加有效，甚至可以设计函数对象的继承体系，以提高代码的扩展能力
 * 3 函数对象通常比普通函数运行速度快
 *   就template而言，更多细节在编译期就已确定，通常可以更好的优化
 *
 * 注意:在多线程环境下使用函数对象，需要特别考虑并发处理
 *
 */
class CFunctionObj
{
public:
	explicit CFunctionObj(std::stringstream &strOutStream) : m_strOutStream(strOutStream) {}
	virtual ~CFunctionObj(void) {}

	void operator() (int elem) const
	{
		m_strOutStream << elem << ' ';
	}

protected:
	std::stringstream &m_strOutStream;
};
