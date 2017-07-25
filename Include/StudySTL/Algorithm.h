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

	/// ��������
	void TestForEach(void);

	/// ��������
	void TestTransform(void);
	void TestTransformMsdn(void);

	/// �жϱ��ʽ
	void TestPredicate(void);

	/// ˫�����жϱ��ʽ
	void TestDoublePredicate(void);

	///	C++��������Lambda�Ż� ���� ��ͨ����
	///	LambdaΪʹ��STL�㷨�����ṩ����߼��ķ��㡢���١��ɶ�����ά��
	/// ��Ⱥ�������:Lambda�ڲ���״̬(��Ա����)�������в����ɵ����߶��壬��ͨ�� [&] [=] ���ݲ���
	void TestLambda(void);

	///	��������(Vector, Deque, Array, List, ForwardList)ʹ��STL�㷨����ʱ��ʹ��Lambda������
	/// ������Ҫ����������ָ��Lambda, ������Ҫdecltype�������ͣ��ڹ�������ʱ��ʾȷ��Lambda����
	void TestLambdaSort(void);

	void TestForEachNew(void);

	void TestFunctionObj(void);

	void TestStlDefaultFuncObj(void);

	void TestBind(void);

protected:
	void Remove1(void);
	void Remove2(void);
	void Remove3(void);

	/// �㷨�ṩ�˷��͵��������ܣ������ھ�����������һ�������ŵ�
	/// ʹ��std::list��ò�Ҫʹ���㷨�ṩ�Ĺ��ܣ��ر���std::remove
	void Remove4(void);

protected:
	explicit CAlgorithm(void);
};

/*! @brief	��������ʹ��˵��
 * 1 ����������һ�ִ�״̬�ĺ���
 *   ���������ӵ�г�Ա�����ͳ�Ա����
 * 2 ���������и��Ե�����
 *   ����template���ͱ�̸�����Ч������������ƺ�������ļ̳���ϵ������ߴ������չ����
 * 3 ��������ͨ������ͨ���������ٶȿ�
 *   ��template���ԣ�����ϸ���ڱ����ھ���ȷ����ͨ�����Ը��õ��Ż�
 *
 * ע��:�ڶ��̻߳�����ʹ�ú���������Ҫ�ر��ǲ�������
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
