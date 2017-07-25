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

	void ErrorUseIter(void);

//////////////////////////////////////////////////////////////////////////
/// ������������(iterator adapter)������ĵ�����

	/// �����͵�����
	/// �����㷨����ʱ��ʹ�ò���(insert)�����Ǹ���(overwrite)
	void InsertIter(void);

	///	����������
	void StreamIter(void);

	/// ���������
	void ReverseIter(void);

	/// �ƶ�������
	void MoveIter(void);

protected:
	explicit CIterator(void);
};

