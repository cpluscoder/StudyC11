#pragma once

#include <CommonDef.h>

class CMySmartPtr
{
	DEFINE_BOOST_SHARED_PTR(CMySmartPtr)
public:
	
	virtual ~CMySmartPtr(void);

	void CreateSharedPtr(void);

	void DefineDeleteOperator(void);

	void DeleteArrayPtr(void);

	void WeakPtr(void);

	void SharedFromThis(void);

protected:
	explicit CMySmartPtr(void);
};

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