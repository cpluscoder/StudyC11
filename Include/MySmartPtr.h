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
///	shared_ptr(共享拥有)
	void CreateSharedPtr(void);

	void DefineDeleteOperator(void);

	void DeleteArrayPtr(void);

	void WeakPtr(void);

	void SharedFromThis(void);

//////////////////////////////////////////////////////////////////////////
///	unique_ptr(独占拥有)
	void TestUniquePtr(void);

	/// 使用场景1:接受unique_ptr的函数
	void FuncRecvUniquePtr(std::unique_ptr<CClassForTest> pData)
	{}

	/// 使用场景2:提供unique_ptr的函数
	std::unique_ptr<CClassForTest> FuncGenerateUniquePtr(void)
	{
		std::unique_ptr<CClassForTest> sp(new CClassForTest);/// sp获取新资源

		/// ...

		/// 不需要返回 std::move(sp), C++标准规定编译器应自动尝试使用std::move
		return sp;///将资源所有权移交给调用者
	}

	void UniquePtrDeleter(void);
	
protected:
	explicit CMySmartPtr(void);

	std::unique_ptr<CClassForTest> m_pSource;/// 推荐使用, 避免引构造时分配内存失败产生异常时产生的内存泄漏
};

