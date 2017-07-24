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

protected:
	explicit CAlgorithm(void);
};

