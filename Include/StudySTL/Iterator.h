#pragma once

#include <CommonDef.h>

class CIterator
{
	DEFINE_BOOST_SHARED_PTR(CIterator)

public:
	
	virtual ~CIterator(void);

	///	iterator:       �� "��/д" ģʽ��������
	/// const_iterator: �� "ֻ��"  ģʽ��������
	/// ++iter �� iter++ Ч�ʸ� (iter++ ��Ҫ��ʱ����)
	void Test(void);

	/// �����������е�Ԫ�ر���˳��
	void TestSet(void);

	/// �����������е�Ԫ��˳��ȷ��
	void TestUnOrderedSet(void);

protected:
	explicit CIterator(void);
};

