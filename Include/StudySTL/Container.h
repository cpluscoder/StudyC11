#pragma once

#include <CommonDef.h>

class CContainer
{
	DEFINE_BOOST_SHARED_PTR(CContainer)

public:
	
	virtual ~CContainer(void);

	/************************************************************************/
	/* 序列容器(Vector, Deque, Array, List, ForwardList)                    */
	/* 使用 数组 或 链表 实现                                               */
	/************************************************************************/
	void SequenceContainer(void);

	/************************************************************************/
	/* 关联式容器(Set, MultiSet, Map, MultiMap)         		            */
	/* 使用 二叉树 实现                                                     */
	/************************************************************************/
	void AssociativeContainer(void);

	/************************************************************************/
	/* 无序容器(Unordered(Multi)Set, Unordered(Multi)Map)                   */
	/* 使用 hash map 实现                                                   */
	/* 查找一个具有特定值的元素时，速度可能快过"关联式容器"                 */
	/* 不允许重复元素                                                       */
	/************************************************************************/
	void UnorderedContainer(void);

	/************************************************************************/
	/* 关联式数组                               		                    */
	/* 索引(下标)不是整数的数组                               		        */
	/************************************************************************/
	void AssociativeArray(void);

	/************************************************************************/
	/* 容器适配器(Stack, Queue, PriorityQueue)                              */
	/* 根据基本容器实现, 提供有限接口                               	    */
	/************************************************************************/
	void Adapter(void);

protected:
	explicit CContainer(void);

//////////////////////////////////////////////////////////////////////////
///	序列容器(SequenceContainer)
	/************************************************************************/
	/* 在vector尾部附件元素或删除元素都十分迅速		                        */
	/* 在vector中间或起始部分插入元素较费时(需要移动元素以保持相对顺序)     */
	/************************************************************************/
	void TestVector(void);

	/************************************************************************/
	/* 动态数组，可以向两端发展			                                    */
	/* 不论在尾部或头部插入元素都十分迅速                                   */
	/* 在中间插入元素则比较费时（需要移动其他元素）                         */
	/************************************************************************/
	void TestDeque(void);

	/************************************************************************/
	/* 固定大小的数组，不可以改变元素个数，只能改变元素值                   */
	/* 必须在建立时就确定大小                                               */
	/************************************************************************/
	void TestArray(void);

	/************************************************************************/
	/* 由双向链表实现,每个元素存在部分内存指向前导和后继元素                */
	/* 不提供随机访问,访问元素需要从链表头顺序移动到所需位置                */
	/* 在任何位置插入或删除都非常迅速                                       */
	/* 访问元素效率比vector/deque低,插入删除比vector/deque高                */
	/************************************************************************/
	void TestList(void);

	/************************************************************************/
	/* 受限的std::list                                                      */
	/* 节省内存，只指向下一个元素                                           */
	/************************************************************************/
	void TestForwardList(void);


//////////////////////////////////////////////////////////////////////////
///	关联式容器(AssociativeContainer)
	/************************************************************************/
	/* 元素可重复的std::set                                                 */
	/* insert后, 默认按 元素值 "operator <" 自动形成顺序                    */
	/************************************************************************/
	void TestMultiSet(void);

	/************************************************************************/
	/* key可重复的std::map                                                  */
	/* insert后, 默认按 key值 "operator <" 自动形成顺序                     */
	/************************************************************************/
	void TestMulteMap(void);

//////////////////////////////////////////////////////////////////////////
///	无序容器(UnorderedContainer)

	void TestUnorderedMultiSet(void);

	void TestUnorderedMap(void);

//////////////////////////////////////////////////////////////////////////
///	关联式数组(AssociativeArray)
	void TestAssociativeArray(void);
};
