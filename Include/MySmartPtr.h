#pragma once

#include <CommonDef.h>

class CClassForTest
{
public:
	explicit CClassForTest(const char *pszData = nullptr, int nSize = 0)
	{
		if(pszData == nullptr || nSize == 0)
		{
			m_pszData = nullptr;
		}
		else if(nSize > 0 && pszData != nullptr)
		{
			int nLen = nSize + 1;
			m_pszData = new char [nLen];
			ZeroMemory(m_pszData, nLen);
			memcpy(m_pszData, pszData, nSize);
		}
		else
		{
			m_pszData = NULL;
		}
	}

	virtual ~CClassForTest(void)
	{
		if(m_pszData != nullptr)
		{
			delete [] m_pszData;
			m_pszData = nullptr;
		}
	}

	const char *Data(void) const { return m_pszData; }


protected:
	char *m_pszData;
};

class CMySmartPtr
{
	DEFINE_BOOST_SHARED_PTR(CMySmartPtr)
public:
	
	virtual ~CMySmartPtr(void);

//////////////////////////////////////////////////////////////////////////
///	shared_ptr(����ӵ��)
	void CreateSharedPtr(void);

	void DefineDeleteOperator(void);

	void DeleteArrayPtr(void);

	void WeakPtr(void);

	void SharedFromThis(void);

//////////////////////////////////////////////////////////////////////////
///	unique_ptr(��ռӵ��)
	void TestUniquePtr(void);

	/// ʹ�ó���1:����unique_ptr�ĺ���
	void FuncRecvUniquePtr(std::unique_ptr<CClassForTest> pData)
	{}

	/// ʹ�ó���2:�ṩunique_ptr�ĺ���
	std::unique_ptr<CClassForTest> FuncGenerateUniquePtr(void)
	{
		std::unique_ptr<CClassForTest> sp(new CClassForTest);/// sp��ȡ����Դ

		/// ...

		/// ����Ҫ���� std::move(sp), C++��׼�涨������Ӧ�Զ�����ʹ��std::move
		return sp;///����Դ����Ȩ�ƽ���������
	}

	void UniquePtrDeleter(void);
	
protected:
	explicit CMySmartPtr(void);

	std::unique_ptr<CClassForTest> m_pSource;/// �Ƽ�ʹ��, ����������ʱ�����ڴ�ʧ�ܲ����쳣ʱ�������ڴ�й©
};

