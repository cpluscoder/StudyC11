#pragma once

#include <CommonDef.h>

/************************************************************************/
/* �㷨û��ʹ���������˼ά��OOP paradigm��                             */
/* ʹ�õ��Ƿ��ͺ������˼ά��generic functional programming paradigm��  */
/* OOP�ǽ������������֯��һ��                                          */
/* ʹ���㷨ʱ����ȷ���ֿ�����ͨ���ض��Ľӿ�ʵ�ֹ���                   */
/* �ر�أ�ĳЩ�������㷨��Ȼ��ǿ����ȴЧ�ʵ���                         */
/************************************************************************/
class CAlgorithm
{
	DEFINE_BOOST_SHARED_PTR(CAlgorithm);
public:
	
	virtual ~CAlgorithm(void);

	void Test(void);

	/// �㷨�е�(����)��������ǰ����ʹ��ǰ����ȷ���������㷨��Ϊδ֪��
	void TestFind(void);

	/// �㷨������(����)����ʱ,��Ҫ����Աȷ����Ŀ�������С >= Դ�����С
	void TestCopy(void);

	/// ʹ�õ����������������㷨,����ͨ���������������������ṩ�ĳ�Ա����
	void TestRemove(void);

protected:
	void Remove1(void);
	void Remove2(void);
	void Remove3(void);
	void Remove4(void);

protected:
	explicit CAlgorithm(void);
};

